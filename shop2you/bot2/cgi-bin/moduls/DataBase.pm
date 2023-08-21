#!/usr/bin/perl -w


package DataBase;
use strict;
use warnings;
use utf8;
use DBI;
use Data::Dumper;

our $singleton = undef;

sub new
{
  my $class     = shift;
  my $db_config = shift;

  return $singleton if defined $singleton;

  my $dbh = DBI->connect(
    $db_config->{data_source}, $db_config->{username},
    $db_config->{password},    $db_config->{attr}
  );
  if ( !$dbh ) { die $DBI::errstr; }
  $dbh->do('SET NAMES cp1251');
  my $self = {
    dbh => $dbh,
  };
  $singleton = bless ($self, $class);
  return $singleton;
}

sub db_disconnect
{
  my $self = shift;
  
  $self->{dbh}->disconnect;
}

1;
