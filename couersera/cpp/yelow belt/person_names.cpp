#include <string>
#include <map>

using namespace std;
string FindName(const map<int, string> &names, int years)
{
  string name;
  auto it = names.upper_bound(years);
  if (it != names.begin())
  {
    name = (--it)->second;
  }
  return name;
}
class Person
{
public:
  void ChangeFirstName(int year, const string &first_name)
  {
    FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string &last_name)
  {
    // добавить факт изменения фамилии на last_name в год year
    LastName[year] = last_name;
  }
  string GetFullName(int year)
  {
    // получить имя и фамилию по состоянию на конец года year
    // с помощью двоичного поиска
    auto first_name = FindName(FirstName, year);
    auto last_name = FindName(LastName, year);
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
      return first_name + " " + last_name;
  }

private:
  // приватные поля
  map<int, string> FirstName;
  map<int, string> LastName;
};
