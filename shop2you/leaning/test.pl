use strict;
use warnings;
use locale;
use utf8;
use Data::Dumper;

sub anagram {
    my $arrayref = shift;
    my $hash;
    foreach my $el (@$arrayref) {
        my $split_el = split( //, lc($el));
        my $sort_el = join( '', sort($split_el));
        foreach my $key ( keys @{$hash} ) {
            my $key_sort = join( '', sort( split( //, $key ) ) );
            if ( $key_sort == $sort_el ) {
                if (!execute $hash->{$key}->{lc($el)} ) {
                push( @{$hash->{$key}}, lc($el));
                }
            }
            else {
                push(@{$hash->{lc($el)}}, lc($el));
            }
        }
    }
    

    return $hash;

    #Write code here
}

my @list = (
    'пятак', 'ЛиСток', 'пятка', 'стул', 'ПяТаК', 'слиток',
    'тяпка', 'столик', 'слиток'
  );
my $result = anagram( \@list );

print Dumper $result;
#print "$_: @{$result->{$_}}" for sort keys %$result;
