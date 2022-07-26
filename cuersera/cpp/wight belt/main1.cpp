#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main (){
    int n;
    vector <string> bro;
    string sister;
    cin >> n;
    while(cin>>sister){
    bro.push_back(sister);
    }
   sort(bro.begin(), bro.end(), [](string a, string b){
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                [](char ch1, char ch2){ return tolower(ch1) < tolower(ch2);});
    });
    for (auto i : bro){
        cout<<i<<" ";
    }
    return 0;
}