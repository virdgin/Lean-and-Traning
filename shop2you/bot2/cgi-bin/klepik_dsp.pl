#!/usr/bin/perl -w
use lib '.';
use strict;
use warnings;
use HTML::Template;

my $db_config = {
    username => "webprog5_klepiktgbot",
    password => "4PaRYFm8k5b2sbSY",
    data_source  => "DBI:mysql:webprog5_klepiktgbot:localhost",
    attr     => { PrintError => 0, RaiseError => 0 }
};


eval {

  require 'moduls/DataBase.pm';
  require 'moduls/CGI.pm';

  my $db = DataBase->new($db_config);

  my $cgi   = CGI->new;
  my $class = $cgi->param_value('class');
  my $event = $cgi->param_value('event');

  if ( $class && $event )
  {
    require 'moduls/' . $class . '.pm';

    my $object = $class-> new();

    $object->$event();
  };

  $db->db_disconnect;
};
if ($@) {
  my $template = HTML::Template->new( filename => 'templates/errors.html' );
  $template->param( errors => $@ );
  print "Content-Type: text/html\n";
  print "Charset: windows-1251\n\n";
  print $template->output;
}
