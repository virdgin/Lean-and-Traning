#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double cifra;
    ifstream input("input.txt");
    cout << fixed << setprecision(3);
    while (input >> cifra)
    {
        cout << cifra << endl;
    }

    return 0;
}