#!/usr/bin/perl -w

package Models;

use lib '.';
use strict;

require 'moduls/CGI.pm';
require 'moduls/DataBase.pm';

my $dbh = DataBase->new()->{dbh};

sub get_groups
{
  my $sth = $dbh->prepare(
"SELECT id, id_tggroup, description, titlegroup FROM klepiktgbot_titlegroup_id"
        );
  $sth->execute();

  return $sth->fetchall_arrayref( {} );
}

sub get_delete_group
{
  my $id_delete = shift;

  my $delete_group =
      $dbh->prepare("DELETE FROM klepiktgbot_titlegroup_id WHERE id = ?");
  $delete_group->execute($id_delete);
}

sub get_add_group
{
  my $id_tggroup  = shift;
  my $titlegroup  = shift;
  my $description = shift;

  my $create_group = $dbh->prepare(
"INSERT INTO klepiktgbot_titlegroup_id SET titlegroup=?,description=?, id_tggroup=? "
    );
  $create_group->execute( $titlegroup, $description, $id_tggroup );

}

sub get_users
{
  my $id = shift;

  my $sth = $dbh->prepare(
"SELECT username, first_name, last_name FROM klepiktgbot_user_id WHERE titlegroup_id = ?"
    );
  $sth->execute($id);

  return $sth->fetchall_arrayref( {} );
}


sub get_homeworks
{
  my $id = shift;
  my $sth = $dbh->prepare(
"SELECT t1.id, t1.description, t1.max_devilery_data, t1.max_rating, AVG(t2.rating) AS ave_rating FROM klepiktgbot_homework_id AS t1 JOIN klepiktgbot_rating_id AS t2 ON t2.homework_id = t1.id WHERE titlegroup_id =  ?"
);
  $sth->execute($id);

  return $sth->fetchall_arrayref({});
}

sub get_rating
{
  my $id = shift;
  my $sth = $dbh->prepare(
    "SELECT t1.username, t2.description, t3.devilery_data, t3.rating
     FROM klepiktgbot_user_id AS t1, 
        klepiktgbot_homework_id AS t2,
        klepiktgbot_rating_id AS t3 
     WHERE t1.titlegroup_id = ?"
);
  $sth->execute($id);
  return $sth->fetchall_arrayref({});
}

1;