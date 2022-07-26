#include <iostream>
using namespace std;
class Incognizable
{
private:
    int a_first;
    int b_first;

public:
    Incognizable(){};
    Incognizable(const int &a)
    {
        a_first = a;
    }
    Incognizable(const int &a, const int &b)
    {
        a_first = a;
        b_first = b;
    };
};
