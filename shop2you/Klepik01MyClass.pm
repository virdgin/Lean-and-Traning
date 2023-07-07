package Klepik01MyClass;


use strict;
use warnings;
use Data::Dumper;


sub new
{
  my ($class) = shift;
  my $self = { stack => [] };

  bless $self, $class;

  return $self; 
}

sub add_value
{
  my ($self, $item) = @_;

  return push @{ $self->{stack} }, $item if $item;
}

sub view_stack
{
  my ($self) =@_;

  # foreach my $el (@{$self->{stack}}) {
  # print "$el, ";}
  print join(", ", @{ $self->{stack}} )."\n";
  # print Dumper \$self;
}

sub print_size_stack
{
  my ($self) = @_;

  print scalar @{ $self->{stack} };
  print "\n";
}

sub is_empty
{
  my $self = @_;

  my $stack = $self->{stack};
  return scalar(@$stack) == 0;
}

sub pop_value
{
  my $self = @_;
  my $stack = $self->{stack};

  if (scalar(@$stack) > 0) {
  my $last_index = scalar(@$stack) - 1;
  my $item = $stack->[$last_index];
  delete $stack->[$last_index] ;
  return $item;}
  
  return 0;
}
1;
