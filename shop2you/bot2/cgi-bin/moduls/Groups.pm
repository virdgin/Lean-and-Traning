#!/usr/bin/perl -w

package Groups;

use lib '.';
use strict;
use warnings;
use HTML::Template;
use Data::Dumper;

require 'moduls/CGI.pm';
require 'moduls/Models.pm';

my $cgi = CGI->new();

sub new {
  my $class = shift;

  my $self = {};
  bless $self, $class;

  return $self;
}

sub show_groups {
  my $self = shift;

  my $template =
    HTML::Template->new( filename =>'templates/klepik_group_list.html' );

  my $groups = Models::get_groups();
  $template->param( groups => $groups );
  print "Content-Type: text/html\n";
  print "Charset: windows-1251\n\n";
  print $template->output;
}

sub delete_group
{
  my $self = shift;
  
  my $group_del = $cgi->param('id');
  Models::get_delete_group( $group_del );

  $self->show_groups();
}


sub add_group
{
  my $self = shift;

  my $id_tggroup = $cgi->param( 'id_tggroup' );
  my $titlegroup = $cgi->param( 'titlegroup' );
  my $description = $cgi->param( 'description' );

  Models::get_add_group($id_tggroup, $titlegroup, $description);

  $self->show_groups;
}

sub show_users
{
  my $self = shift;
  
  my $id       = $cgi->param('id');
  my $users = Models::get_users($id);

  my $template = HTML::Template->new( filename => 'templates/klepik_users_list.html' );
  $template->param(users => $users);

  print "Content-Type: text/html\n";
  print "Charset: windows-1251\n\n";
  print $template->output;
}

sub show_homeworks
{
  my $self = shift; 

  my $id = $cgi->param('id');
  my $homeworks = Models::get_homeworks($id);
  
  my $template =
  HTML::Template->new( filename => 'templates/klepik_homework_list.html' );
  $template->param( homeworks => $homeworks );

  print "Content-Type: text/html\n";
  print "Charset: windows-1251\n\n";
  print $template->output;
}

sub show_rating
{
  my $self = shift; 
  
  my $id = $cgi->param('id');
  my $rating = Models::get_rating($id);

  my $template = HTML::Template->new( filename => 'templates/klepik_rating_list.html' );
  $template->param( rating => $rating );

  print "Content-Type: text/html\n";
  print "Charset: windows-1251\n\n";

  print $template->output;
}

1;
