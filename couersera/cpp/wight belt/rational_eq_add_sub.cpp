#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
void reduce(int &a, int &b)
{
    int c = gcd(a, b);
    a /= c;
    b /= c;
}

class Rational
{
public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator)
    {
        reduce(new_numerator, new_denominator);
        if (new_denominator > 0)
        {
            numerator = new_numerator;
            denominator = new_denominator;
        }
        else
        {
            numerator = -new_numerator;
            denominator = -new_denominator;
        }
    }
    int Numerator() const
    {
        return numerator;
    }

    int Denominator() const
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};
bool operator==(const Rational &lhs, const Rational &rhs)
{
    int l = lhs.Numerator() * rhs.Denominator();
    int r = rhs.Numerator() * lhs.Denominator();
    return l == r;
}

Rational operator+(const Rational &lhs,const Rational &rhs)
{
    
        int l = lhs.Numerator() * rhs.Denominator();
        int r = rhs.Numerator() * lhs.Denominator();
        int gen = lhs.Denominator() * rhs.Denominator();
        return Rational(l + r, gen);
    
}
Rational operator-(const Rational &lhs,const Rational &rhs)
{
    int l = lhs.Numerator() * rhs.Denominator();
    int r = rhs.Numerator() * lhs.Denominator();
    int gen = lhs.Denominator() * rhs.Denominator();
    return Rational(l - r, gen);
}
int main()
{
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal)
        {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal)
        {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal)
        {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    {
        Rational r = Rational(1, 2) + Rational(3, 4);
        bool equal = r == Rational(5, 4);
        if (!equal)
        {
            cout << "nothing" << endl;
            return 4;
        }
    }
    cout << "OK" << endl;
    return 0;
}