package Klepik01MyClass;

use strict;
use warnings;

sub new {
    my ($class) = shift;

    my $self = { stack => [] };
    bless $self, $class;
    return $self;
}

