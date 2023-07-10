#!/usr/bin/perl
use 5.01;
use strict;
use warnings;
use utf8;
use Data::Dumper;

use FindBin qw($Bin);
use lib $Bin;
use lib 'Lean-and-Traning/shop2you/bot';
use WebProgTelegramClient;

my $token       = '6388921702:AAEOgItXWWealZR_fbxEDS_1hYqJ2lCfIjA';
my $tittle_chat = 'test_group_bot';
my $bot         = WebProgTelegramClient->new( token => $token );
# my @chat_updates = @{ $chat->{result}};
my %users;
while (1) {
    my $chat    = $bot->call( 'getUpdates', { offset => -1 } );
    my $message = $chat->{result}[0]{message};
    my $chat_id = $message->{chat}->{id};
    if ($message) {
        my $user_name = $message->{from}->{first_name};
        my $user_id   = $message->{from}->{id};
        if ( $message->{new_chat_members} ) {
            for my $new_user ( @{ $message->{new_chat_members} } ) {
                $users{ $new_user->{id} } = '0';
            }
        }
        elsif ( $message->{left_chat_member} ) {
            my $left_user_id = $message->{left_chat_member}->{id};
            if ( exists $users{$left_user_id} ) {
                my $left_user = $message->{left_chat_member}->{first_name};
                $bot->call(
                    'sendMessage',
                    {
                        chat_id => $chat_id,
                        text    => "Желаем удачи, \@$left_user!"
                    }
                );
                delete $users{$left_user_id};
            }
        }
        elsif ( $users{$user_id} == '0' && $message->{text} ) {
            $users{$user_id} = '1';
            $bot->call( 'sendMessage',
                { chat_id => $chat_id, text => "Привет, \@$user_name" } );
        }
    }
}

# print Dumper \@chat_updates;

