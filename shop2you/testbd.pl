use FindBin qw( $Bin );
use lib $Bin;
use warnings;
use strict;
use lib '.';
use Data::Dumper;
use TestBD;

my $homeworks = [
    {
        'id'                => 1,
        'description'       => 'Создать БД',
        'max_rating'        => 100,
        'max_devilery_data' => '2023-07-19'
    },
    {
        'id'                => 2,
        'max_devilery_data' => '2023-07-24',
        'description'       => 'all incl',
        'max_rating'        => 100
    }
];

my $rating = [
    {
        homework_id => 1,
        ave_rating  => 100
    },
    {
        homework_id => 1,
        ave_rating  => 100
    },
    {
        homework_id => 2,
        ave_rating  => 50
    },
      {
        homework_id => 2,
        ave_rating  => 50
      }
];
my $result;
foreach my $rat ( @$rating){
    my $row;
    if (scalar $result == 0) {
        my $row->{
            homework_id => $rat->{homework_id},
        }
    }
    
}
foreach my $key (@$homeworks) {

    foreach my $hom (@$rating){
        if ($key->{id} == $hom->{homework_id}){
            $key->{ave_rating} = $hom->{ave_rating};
        } 
    }
}

die Dumper $result;
