#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    int number;
    map<set<string>, int> buses;
    for (int i=0; i<Q;i++){
        cin>>number;
        set<string> stops;
         string stop;
        for (int j=0;j<number;j++){        
        cin>>stop;
        stops.insert(stop);
        }
        if (buses.count(stops)==0){
            buses[stops]=buses.size()+1;
            cout <<"New bus "<<buses[stops]<<endl;
        }
        else cout <<"Already exists for " << buses[stops]<<endl;
        }
    return 0;
}