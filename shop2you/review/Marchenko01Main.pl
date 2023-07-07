use strict;
use lib 'Lean-and-Traning/shop2you/review';
use Marchenko01Stack;

my $stack = Marchenko01Stack->new();
$stack->push(5);
$stack->push(10);
$stack->push(15);

print "Size: " . $stack->size() . "\n";

print $stack->pop() . "\n";
print $stack->pop() . "\n";

if ($stack->is_empty()) 
{
  print "Stack is empty\n";
} 
else 
{
  print "Stack is not empty\n";
}

print $stack->pop() . "\n";

if ($stack->is_empty()) 
{
  print "Stack is empty\n";
} 
else 
{
  print "Stack is not empty\n";
}
