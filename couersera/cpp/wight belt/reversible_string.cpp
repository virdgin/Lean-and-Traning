//Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString для получения строки.
#include <iostream>
#include <algorithm>
#include <string>

class ReversibleString
{
public:
    ReversibleString() {}
    ReversibleString(const string &words)
    {
        word = words;
    }
    void Reverse()
    {
        reverse(begin(word), end(word));
    }
    string ToString() const
    {
        return word;
    }

private:
    string word;
};