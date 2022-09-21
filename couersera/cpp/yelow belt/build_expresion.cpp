#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string result;
    int qualitty = 0;
    cin >> result >> qualitty;
    result.insert(0, qualitty, '(');
    for (int i = 0; i < qualitty; i++)
    {
        string operation;
        string temp;
        cin >> operation >> temp;
        result += ") " + operation + " " + temp;
    }
    cout << result;
    return 0;
}