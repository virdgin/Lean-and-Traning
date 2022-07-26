#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student
{
    string First_Name;
    string Last_Name;
    int birth_day;
    int birth_month;
    int birth_year;
};

int main()
{
    int n;
    cin >> n;
    string First_Name, Last_Name;
    int birth_day, birth_month, birth_year;
    vector<Student> students;
    for (int i = 0; i < n; i++)
    {
        cin >> First_Name >> Last_Name >> birth_day >> birth_month >> birth_year;
        students.push_back(Student{
            First_Name,
            Last_Name,
            birth_day,
            birth_month,
            birth_year});
    }
    int m;
    int number;
    string command;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> command >> number;
        --number;
        if (command == "name" && number >= 0 && number < n)
        {
            cout << students[number].First_Name << " " << students[number].Last_Name << endl;
        }
        else if (command == "date" && number >= 0 && number < n)
        {
            cout << students[number].birth_day << "." << students[number].birth_month << "." << students[number].birth_year << endl;
        }
        else
            cout << "bad request" << endl;
    }
    return 0;
}