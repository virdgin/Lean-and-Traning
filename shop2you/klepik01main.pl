#!/usr/bin/perl
use 5.01;
use strict;
use warnings;

use lib 'Lean-and-Traning/shop2you';
use Klepik01MyClass;
use Data::Dumper;

my $cl = Klepik01MyClass->new();

$cl->add_value(10);

$cl->add_value(20);

$cl->pop_value();

$cl->view_stack();

$cl->print_size_stack();
