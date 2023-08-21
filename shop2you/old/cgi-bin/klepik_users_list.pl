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

my $template = HTML::Template->new( filename => 'klepik_users_list.html' );
my $id       = $io_cgi->param('id');

my $sth = $dbh->prepare(
"SELECT username, first_name, last_name FROM klepiktgbot_user_id WHERE titlegroup_id = ?"
);
$sth->execute($id);
my @users;
while ( my $row = $sth->fetchrow_hashref() ) {
    push @users, $row;
}

$template->param( users => \@users );
$sth->finish;
$dbh->disconnect;

print "Content-Type: text/html\n";
print "Charset: windows-1251\n\n";

print $template->output;

