use DBI;
use Data::Dumper;
use strict;
use warnings;
use utf8;
use Encode;

# Подключение к БД
my $attr = {PrintError => 0, RaiseError => 0};
my $data_source = "DBI:mysql:webprog5_klepiktgbot:localhost";
my $username = "webprog5_klepiktgbot";
my $password = "4PaRYFm8k5b2sbSY";
my $dbh = DBI->connect($data_source, $username, $password, $attr);
if (!$dbh) { die $DBI::errstr; }
# $dbh->do('SET NAMES cp1251');


# Выполнение запроса к БД
my $rv = $dbh->selectall_arrayref('SELECT DISTINCT devilery_data,max_devilery_data,discriptions, username, rating FROM klepiktgbot_homework_id, klepiktgbot_user_id,klepiktgbot_rating_id
ORDER BY max_devilery_data;');

die Dumper \$rv;
