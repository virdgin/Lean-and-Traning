package Marchenko01Stack;
use strict;

sub new 
{
  my $class = shift;
  my $self = {
    stack => [],
  };
  bless $self, $class;
  return $self;
}

sub push
{
  my ($self, $item) = @_;
  my $stack = $self->{stack};
  $stack->[scalar(@$stack)] = $item;
}

sub pop
{
  my $self = shift;
  my $stack = $self->{stack};
  my $last_index = scalar(@$stack) - 1;
  my $item = $stack->[$last_index];
  delete $stack->[$last_index];
  return $item;
}

sub is_empty
{
  my $self = shift;
  my $stack = $self->{stack};
  return scalar(@$stack) == 0;
}

sub size
{
  my $self = shift;
  my $stack = $self->{stack};
  return scalar(@$stack);
}

1;