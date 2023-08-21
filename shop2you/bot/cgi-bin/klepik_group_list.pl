#!/usr/bin/perl -w
use strict;
use warnings;
use utf8;
use DBI;
use FindBin qw($Bin);
use lib $Bin;
use lib '.';
require 'io_cgi.pl';
use HTML::Template;

# Дебаг
use Data::Dumper;

# Подключение к БД
my $attr        = { PrintError => 0, RaiseError => 0 };
my $data_source = "DBI:mysql:webprog5_klepiktgbot:localhost";
my $username    = "webprog5_klepiktgbot";
my $password    = "4PaRYFm8k5b2sbSY";

my $dbh = DBI->connect( $data_source, $username, $password, $attr );
if ( !$dbh ) { die $DBI::errstr; }

$dbh->do('SET NAMES cp1251');

my $io_cgi = 'io_cgi'->new;
$io_cgi->get_params();

my $id          = $io_cgi->param('id_tggroup');
my $title       = $io_cgi->param('titlegroup');
my $description = $io_cgi->param('description');

# Для удаления группы
my $delete = $io_cgi->param('group_to_delete');

if ($id) {
    my $create_group = $dbh->prepare(
"INSERT INTO klepiktgbot_titlegroup_id SET titlegroup=?,description=?, id_tggroup=? "
    );
    $create_group->execute( $title, $description, $id );
}

if ($delete) {
    my $delete_group =
      $dbh->prepare("DELETE FROM klepiktgbot_titlegroup_id WHERE id = ?");
    $delete_group->execute($delete);
}

# Выполнение запроса к БД
my $sth = $dbh->prepare("SELECT * FROM klepiktgbot_titlegroup_id");
$sth->execute();
my @groups;
while ( my $row = $sth->fetchrow_hashref() ) {

    my $user_link     = "klepik_users_list.pl?id=" . $row->{id};
    my $rating_link   = "klepik_rating_list.pl?id=" . $row->{id};
    my $homework_link = "klepik_homework_list.pl?id=" . $row->{id};

    $row->{rating_link}   = $rating_link;
    $row->{user_link}     = $user_link;
    $row->{homework_link} = $homework_link;

    push @groups, $row;
}

# die Dumper \$rv;

my $template = HTML::Template->new( filename => 'klepik_group_list.html' );

$template->param( groups => \@groups );

print "Content-Type: text/html\n";
print "Charset: windows-1251\n\n";
print $template->output;

$sth->finish;
$dbh->disconnect;
