use strict;
use warnings;
use utf8;
use Data::Dumper;
use Encode;
use FindBin qw($Bin);
use lib $Bin;
use lib '.';
use WebProgTelegramClient;

my $token       = '6388921702:AAEOgItXWWealZR_fbxEDS_1hYqJ2lCfIjA';
my $tittle_chat = 'test_group_bot';
my $bot         = WebProgTelegramClient->new( token => $token );
my $users;

sub check_sended_message {
    my $message=shift;
    my $check_messege =
         [
    'text', 
    'photo', 
    'audio', 
    'video', 
    'voice', 
    'animation', 
    'document', 
    'poll',
    'location',
    'contact',
  ];
    for my $check ( @$check_messege){
        if($message->{$check}){
            return 1;
        }
    }
    return 0;
}
sub send_hi{
    my $message=shift;
    my $user_id = $message->{from}->{id};
    if (defined($users->{$user_id}->{quanty_massage}) && $users->{$user_id}->{quanty_massage} == 0){
        my $user_name = $users->{$user_id}->{first_name};
        my $id_messege = $message->{message_id};
        $bot->call('sendMessage', {chat_tittle => $tittle_chat, text => "Привет, \@$user_name!", reply_to_message_id => $id_messege});
        $users->{$user_id}->{quanty_massage} == 1;
    }
}

sub send_bay{
    my $left_member = shift;
    my $user_name = $left_member->{first_name};
    $bot->call('sendMessage', {chat_tittle => $tittle_chat, text=> "Желаем удачи, $user_name"});
    delete $users->{$left_member->{id}};
}

sub update_users{
    my $message = shift;
    my $user_id = $message->{new_chat_member}->{id};
    my $info_users = {
        first_name => $message->{new_chat_member}->{first_name},
        quanty_massage => 0,
    };
    $users->{$user_id} = $info_users;
}

my $chat_id;
while(1){

    my $chat_message = $bot->read_chat(tittle_chat => $tittle_chat);

    if (scalar @$chat_message !=0){

        my $last_chat_id = $chat_message->[-1]->{update_id};

        while ($last_chat_id && $chat_message){

           my $update_messages = shift @$chat_message;
           my $current_chat_id = $update_messages->{update_id};

           if ($current_chat_id > $last_chat_id){

            if ($update_messages->{message}->{new_chat_member}){

                update_users($update_messages->{message});
            }
            elsif ($update_messages->{message}->{left_chat_member}){

                send_bay($update_messages->{message}->{left_chat_member});
            }
            elsif ($update_messages->{message}){
            
                send_hi($update_messages->{message});
            }
           }
        }
        $chat_id = $last_chat_id;
    }
}


# print Dumper \@chat_updates;

