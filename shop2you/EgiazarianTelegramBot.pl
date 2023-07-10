use FindBin qw( $Bin );
use lib $Bin;
use warnings;
use strict;
use lib '.';

use utf8;
use Encode;
use Time::HiRes qw(usleep);

use WebProgTelegramClient;

=pod


=head1 NAME

EgiazarianTelegramBot - создает объект клиента WebProgTelegramClient

=head1 DESCRIPTION

  При запуске игнорирует все апдейты, которые были на предыдущих запусках,
  чтобы не заспамить чат сообщениями.

  Включается бесконечный цикл, который на каждой итерации читает чат (с задержкой в 0.5 сек)
  если видит новое обновление, то реагирует на него в соответствие с задачей

=cut


my $BOT_TOKEN = '';
my $chat_id = '-986129112';
my $users = {};

my $bot = WebProgTelegramClient->new(token => $BOT_TOKEN);

=head2 check_sended_message(message => XXX)

Принимает апдейт в виде хеша

Проверяет тип отправленного сообщения
возвращает true, если тип сообщения есть в списке

Функция нужна для более гибкого управления ответами на сообщения, 
на случай, если мы не хотим реагировать приветствием на какой-то из типов сообщения

=cut
sub check_sended_message
{
  my $message = shift;

  my $checking_list =
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

  foreach my $message_type (@$checking_list)
  {
    if ( $message->{$message_type} )
    {
      return 1;
    }
  }
  return 0;
}

=head2 update_users_db(message => XXX)

Принимает апдейт в виде хеша

Обновляет нашу "игрушечную" БД, добавляет сведения о вновь добавившемся пользователе

=cut
sub update_users_db 
{
  my $message = shift;

  my $user_id = $message->{new_chat_member}->{id};
  my $info = 
  {
    first_name => $message->{new_chat_member}->{first_name},
    has_written_message => 0,
  };
  $users->{$user_id} = $info;
}


=head2 say_hi(message => XXX)

Принимает апдейт в виде хеша

Отвечает приветствием, если сообщение первое от пользователя

Меняет флаг, который маркирует, написал ли пользователь свое первое сообщение
=cut
sub say_hi 
{
  my $message = shift;
 
  my $user_id = $message->{from}->{id};

  if ( defined( $users->{$user_id}->{has_written_message} ) 
    and $users->{$user_id}->{has_written_message} == 0 )
  { 
    my $user_name = $users->{$user_id}->{first_name};
    my $message_id = $message->{message_id};

    # Отправляем приветствие
    $bot->call('sendMessage', {
      chat_id => $chat_id,
      text => "Привет, $user_name!",
      reply_to_message_id => $message_id,
    }
    );
    $users->{$user_id}->{has_written_message} = 1;
  }
}



# Инициализируем переменную в которую будем класть id последнего апдейта из предыдущей итерации
my $prev_update_id;

#################################################### ГЛАВНЫЙ ЦИКЛ ####################################################
while (1) 
{
  # Получаем все сообщения на текущией итерации
  my $messages = $bot->read_chat( chat_id => $chat_id );
  
  if (scalar @$messages != 0)
  {
    # Получаем id последнего апдейта на текущей итерации
    my $last_update_id = $messages->[-1]->{update_id};

    # Запускаем цикл пока не вытащим все апдейты или не дойдем до старого апдейта из предыдущей итерации
    while ($prev_update_id and @$messages) 
    { 
      # Забираем апдейты с начала списка (в начале лежат более старые апдейты)
      my $update = shift @$messages;
      my $current_update_id = $update->{update_id};

      # Если id прочитанного обновления больше последнего, значит обновление новое
      # Запускается весь процесс обработки новых апдейтов 
      if ($current_update_id > $prev_update_id)
      {
        # Если апдейт содержит информацию о новом участнике
        if ($update->{message}->{new_chat_member})
        {
          update_users_db($update->{message});
        }

        # Проверка на то, что пользователь вышел из группы
        elsif ($update->{message}->{left_chat_member})
        { 
          my $name = $update->{message}->{left_chat_member}->{first_name};
          my $current_user_id = $update->{message}->{left_chat_member}->{id};
          
          $bot->call( 'sendMessage', { chat_id => $chat_id, text => "Желаем удачи, $name!" } );
          
          # Удаляем сведения о пользователе из БД
          delete $users->{$current_user_id};
        }

        # Проверка явялется ли сообщение первым присланным от пользователя
        elsif ( check_sended_message($update->{message}) )
        { 
          say_hi($update->{message});
        }
      }
    }
    # Запоминаем последний апдейт из только-что обработанных
    $prev_update_id = $last_update_id;
  }
  usleep(500_000);
}

