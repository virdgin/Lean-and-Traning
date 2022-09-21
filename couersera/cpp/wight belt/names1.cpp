#include <map>
#include <iostream>

using namespace std;
class Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        FirstName[year] = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
        LastName[year] = last_name;
    }
    string GetFullName(int year)
    {
        string first_name;
        string last_name;
        for (const auto &i : FirstName)
        {
            if (year >= i.first)
            {
                first_name = i.second;
            }
            else
            {
                break;
            }
        }
        for (const auto &j : LastName)
        {
            if (year >= j.first)
            {
                last_name = j.second;
            }
            else
            {
                break;
            }
        }

        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";
        }
        else if (first_name.empty())
        {
            return last_name + " with unknown first name";
        }
        else if (last_name.empty())
        {
            return first_name + " with unknown last name";
        }
        else
        {
            return first_name + " " + last_name;
        }
        // получить имя и фамилию по состоянию на конец года year
    }

private:
    map<int, string> FirstName;
    map<int, string> LastName;
};
