#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
enum class Gender
{
  FEMALE,
  MALE
};

struct Person
{
  int age;          // возраст
  Gender gender;    // пол
  bool is_employed; // имеет ли работу
};
*/

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);
void PrintStats(vector<Person> persons);

int main()
{
  return 0;
}

void PrintStats(vector<Person> persons)
{
  cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

  cout << "Median age for females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                     { return value.gender == Gender::FEMALE; }))
       << endl;

  cout << "Median age for males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                   { return value.gender == Gender::MALE; }))
       << endl;

  cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                              { return value.gender == Gender::FEMALE && value.is_employed; }))
       << endl;

  cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                                { return value.gender == Gender::FEMALE && !value.is_employed; }))
       << endl;

  cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                            { return value.gender == Gender::MALE && value.is_employed; }))
       << endl;

  cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(), [](const Person &value)
                                                                                              { return value.gender == Gender::MALE && !value.is_employed; }))
       << endl;
}
