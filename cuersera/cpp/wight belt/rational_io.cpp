#include <iostream>
#include <sstream>
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

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4")
        {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal)
        {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct)
        {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct)
        {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}