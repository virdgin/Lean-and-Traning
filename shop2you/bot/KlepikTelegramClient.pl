use strict;
use warnings;
use utf8;
use Data::Dumper;
use Encode;
use FindBin qw($Bin);
use lib $Bin;
use lib '.';
use Time::HiRes qw(usleep);

use WebProgTelegramClient;

my $token       = '6388921702:AAEOgItXWWealZR_fbxEDS_1hYqJ2lCfIjA';
my $tittle_chat = 'test_group_bot';
my $bot         = WebProgTelegramClient->new( token => $token );
my $users       = {};
my $prev_update_id;
my $chat_id = '-905661021';

sub check_messege {
    my $message   = shift;
    my $chek_list = [
        'text',     'photo',     'audio',    'video',
        'voice',    'animation', 'document', 'poll',
        'location', 'contact',
    ];
    for my $check (@$chek_list) {
        return 1 if defined $message->{$check};
    }
    return 0;
}

sub users_db {
    my $new_message   = shift;
    my $new_member_id = $new_message->{id};
    my $user_info     = {
        first_name     => $new_message->{first_name},
        username       => $new_message->{username} || "None",
        number_message => 0,
    };
    $users->{$new_member_id} = $user_info;
}

sub send_by {
    my $new_message      = shift;
    my $left_member_id   = $new_message->{new_chat_member}->{id};
    my $left_member_name = $new_message->{new_chat_member}->{first_name};
    my $left_username = $new_message->{new_chat_member}->{username} || "None";
    my $chat_id       = $new_message->{chat}->{id};
    my $text;
    if ( $left_username != "None" ) {
        $text = "Желаем удачи, \@$left_username!";
    }
    else {
        $text = "Желаем удачи, \@$left_member_name!";
    }
    $bot->call( 'sendMessage', { chat_id => $chat_id, text => $text } );
    delete $users->{$left_member_id};
}

sub send_hi {
    my $message = shift;
    my $chat_id = $message->{chat}->{id};
    my $user_id = $message->{from}->{id};
    if ( defined $users->{$user_id}
        && $users->{$user_id}->{number_message} == 0 )
    {
        my $message_id = $message->{message_id};
        my $first_name = $users->{$user_id}->{first_name};
        my $username   = $users->{$user_id}->{username};
        my $text;
        if ( $username == "None" ) {
            $text = "Привет, \@$first_name!";
        }
        else {
            $text = "Привет, \@$username!";
        }
        $bot->call(
            'sendMessage',
            {
                chat_id             => $chat_id,
                reply_to_message_id => $message_id,
                text                => $text
            }
        );
    }
    $users->{$user_id}->{number_message} = 1;
}

while (1) {

    # получаем содержимое чата
    my $chat = $bot->read_chat( chat_title => $tittle_chat );
    if ( scalar @$chat != 0 ) {

        # пока есть сообщения и нет обновлений чата
        my $last_update_id = $chat->[-1]->{update_id};
        while ( $prev_update_id && @$chat ) {
            my $update    = shift @$chat;
            my $valide_id = $update->{update_id};
            if ( $valide_id > $prev_update_id ) {

                # проверяем нового участника
                if ( $update->{message}->{new_chat_member} ) {
                    users_db( $update->{message}->{new_chat_member} );
                }

                # проверяем не покинул ли нас кто
                elsif ( $update->{message}->{left_chat_member} ) {
                    send_by( $update->{message} );
                }
                elsif ( check_messege( $update->{message} ) ) {
                    send_hi( $update->{message} );
                }
            }
        }
        $prev_update_id = $last_update_id;
    }
    usleep(500_000);
}

