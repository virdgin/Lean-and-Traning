package MyClass;

use strict;
use warnings;

my $stack_size = 20;

sub new {
    my($class) = @_;
    
    my $self = {
        stack => []
    };

    return bless $self, $class;
}

# returns the number of elements in the stack
sub push_onto_stack {
    my ($self, $item) = @_;
    die "Overflow\n" if @{$self->{stack}} > $stack_size;
    return push @{$self->{stack}}, $item;
}


1;