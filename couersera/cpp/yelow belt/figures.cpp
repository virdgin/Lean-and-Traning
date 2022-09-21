#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure
{
public:
    Figure() = default;
    Figure(const string &name) : _name(name)
    {
    }
    string Name() const
    {
        return _name;
    }
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

private:
    string _name;
};
class Triangle : public Figure
{
public:
    Triangle() : Figure("TRIANGLE") {}
    Triangle(double _a, double _b, double _c) : Figure("TRIANGLE"),
                                                a(_a),
                                                b(_b),
                                                c(_c)
    {
    }
    double Perimeter() const override
    {
        return a + b + c;
    }
    double Area() const override
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

private:
    double a,
        b,
        c;
};
class Rect : public Figure
{
public:
    Rect() : Figure("RECT") {}
    Rect(double _x, double _y) : Figure("RECT"), x(_x), y(_y) {}
    double Perimeter() const override
    {
        return 2 * x + 2 * y;
    }
    double Area() const override
    {
        return x * y;
    }

private:
    double x, y;
};
const double Pi = 3.14;
class Circle : public Figure
{
public:
    Circle() : Figure("CIRCLE") {}
    Circle(double _r) : Figure("CIRCLE"), r(_r) {}
    double Perimeter() const override
    {
        return 2 * Pi * r;
    }
    double Area() const override
    {
        return Pi * r * r;
    }

private:
    double r;
};

shared_ptr<Figure> CreateFigure(istringstream &is)
{
    double a, b, c;
    string temp;
    is >> temp;
    if (temp == "TRIANGLE")
    {
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    if (temp == "RECT")
    {
        is >> a >> b;
        return make_shared<Rect>(a, b);
    }
    if (temp == "CIRCLE")
    {
        is >> a;
        return make_shared<Circle>(a);
    }
    throw invalid_argument(temp);
}

int main()
{
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);)
    {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD")
        {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT")
        {
            for (const auto &current_figure : figures)
            {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}