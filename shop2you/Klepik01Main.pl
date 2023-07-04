use 5.01;
use strict;
use warnings;

use Klepik01MyClass;

my $cl = Klepik01MyClass->new();
print "Welcome to \'stack\'\n";
print "Available commands:\n";
print "ADD n - added new element in stack\n";
print "FIRST - return first element\n";
print "LAST - return last element\n";
print "VIEW - return stack view\n";
print "DEL n - delete element if n not in stack return \'not found\'\n";

while (<STDIN>) {
    print "Enter the command:\n";

}
