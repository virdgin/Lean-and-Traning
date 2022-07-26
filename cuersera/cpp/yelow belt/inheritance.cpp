#include <iostream>

using namespace std;

class Animal
{
public:
    // ваш код
    Animal(const string &_name) : Name(_name) {}
    const string Name;
};

class Dog : public Animal
{
public:
    // ваш код
    Dog(const string &name) : Animal(name)
    {
    }
    void Bark()
    {
        cout << Name << " barks: woof!" << endl;
    }
};