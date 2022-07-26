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
        if (d != 0)
        {
            rational = Rational(n, d);
        }
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3)
        {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs)
        {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
        {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2)
        {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}