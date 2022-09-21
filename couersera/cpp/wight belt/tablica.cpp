#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int a = 0, b = 0;
    ifstream input("E:\\Code\\cuersera\\input.txt");
    if (input.is_open())
    {
        input >> a;
        input.ignore(1);
        input >> b;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                int cifra;
                input >> cifra;
                cout << setw(10) << cifra;
                if (j != b - 1)
                {
                    input.ignore(1);
                    cout << ' ';
                }
            }
            if (i != a - 1)
            {
                cout << endl;
            }
        }
    }
    return 0;
}