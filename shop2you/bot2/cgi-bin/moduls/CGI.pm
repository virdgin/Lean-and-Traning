#!/usr/bin/perl -w

package CGI;

use lib '/cgi-bin';
use strict;
use warnings;
require 'io_cgi.pl';

our $singleton = undef;

sub new
{
  my $class = shift;

  return $singleton if defined $singleton;

  $singleton = 'io_cgi'->new;;

  return $singleton;
}


1;