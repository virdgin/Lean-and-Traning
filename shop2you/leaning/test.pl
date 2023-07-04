use strict; 
use warnings;

use MyClass;


my $cl = MyClass->new();

print $cl->push_onto_stack(10);
print "\n";
print $cl->push_onto_stack(20);