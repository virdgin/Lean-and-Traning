#include <iostream>
#include <map>
#include <set>
#include <vector>
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
        if (new_denominator == 0)
        {
            throw invalid_argument("denominator by zero");
        }
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
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator/(const Rational &lhs, const Rational &rhs)
{
    if (rhs.Numerator() == 0)
    {
        throw domain_error("divinity error");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), rhs.Numerator() * lhs.Denominator());
}
istream &operator>>(istream &stream, Rational &rational)
{
    if (stream)
    {
        int n = 0, d = 0;
        char s;
        stream >> n;
        stream >> s;
        if (s != '/')
        {
            return stream;
        }
        stream >> d;
        rational = Rational(n, d);
    }

    return stream;
}
ostream &operator<<(ostream &stream, const Rational &rational)
{
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}
bool operator<(const Rational &lhs, const Rational &rhs)
{
    return (lhs - rhs).Numerator() < 0;
}

int main()
{
    try
    {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument &)
    {
    }

    try
    {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error &)
    {
    }

    cout << "OK" << endl;
    return 0;
}