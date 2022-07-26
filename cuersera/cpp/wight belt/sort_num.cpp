#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool Min(const int& a, const int& b){
    return abs(a)<abs(b);
}
int main(){
    int n,q;
    cin >>n;
    vector<int>gunster;
    while(cin>>q){
        gunster.push_back(q);
    }
    sort(begin(gunster), end(gunster), Min);
    for (auto i : gunster){
        cout << i<<" ";
    }
    return 0;
}