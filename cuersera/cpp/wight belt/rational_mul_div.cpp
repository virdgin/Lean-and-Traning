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

Rational operator+(const Rational &lhs, const Rational &rhs)
{

    int l = lhs.Numerator() * rhs.Denominator();
    int r = rhs.Numerator() * lhs.Denominator();
    int gen = lhs.Denominator() * rhs.Denominator();
    return Rational(l + r, gen);
}
Rational operator-(const Rational &lhs, const Rational &rhs)
{
    int l = lhs.Numerator() * rhs.Denominator();
    int r = rhs.Numerator() * lhs.Denominator();
    int gen = lhs.Denominator() * rhs.Denominator();
    return Rational(l - r, gen);
}
Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator/(const Rational &lhs, const Rational &rhs)
{
    int l = lhs.Numerator() * rhs.Denominator();
    int r = rhs.Numerator() * lhs.Denominator();
    return Rational(l, r);
}
int main()
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal)
        {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal)
        {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}