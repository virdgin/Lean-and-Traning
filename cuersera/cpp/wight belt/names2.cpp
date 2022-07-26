#include <map>
#include <iostream>
#include <vector>

using namespace std;
class Person
{
public:
    string PrintVector(const vector<string> &v)
    {
        if (v.empty())
        {
            return "";
        }
        string prv;
        string output = " (";
        output += v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--)
        {
            output += ", " + v[i];
        }
        output += ")";
        return output;
    }
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
    string GetFullNameWithHistory(int year)
    {
        string name;
        string lastname;
        vector<string> n1;
        vector<string> ln;
        for (const auto &i : FirstName)
        {
            if (year >= i.first)
            {
                if (!name.empty() && name != i.second)
                {
                    n1.push_back(name);
                }
                name = i.second;
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
                if (!lastname.empty() && lastname != j.second)
                {
                    ln.push_back(lastname);
                }
                lastname = j.second;
            }
            else
            {
                break;
            }
        }
        if (name.empty() && lastname.empty())
        {
            return "Incognito";
        }
        else if (name.empty())
        {
            return lastname + PrintVector(ln) + " with unknown first name";
        }
        else if (lastname.empty())
        {
            return name + PrintVector(n1) + " with unknown last name";
        }
        else
        {
            return name + PrintVector(n1) + " " + lastname + PrintVector(ln);
        }

        // получить все имена и фамилии по состоянию на конец года year
    }

private:
    map<int, string> FirstName;
    map<int, string> LastName;
};