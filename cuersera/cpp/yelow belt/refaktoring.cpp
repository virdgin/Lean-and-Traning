#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People
{
public:
    People(const string &_type, const string &prof) : Name(prof), Type(_type)
    {
    }

    virtual void Walk(const string &destination) const = 0;

    string Prof() const
    {
        return Name;
    }
    string type_() const
    {
        return Type;
    }

protected:
    const string Name;
    const string Type;
};

class Student : public People
{
public:
    Student(string name, string favouriteSong) : People("Student", name),
                                                 FavouriteSong(favouriteSong)
    {
    }
    void Learn() const
    {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(const string &destination) const override
    {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const
    {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};

class Teacher : public People
{
public:
    Teacher(const string &name, string subject) : People("Teacher", name), Subject(subject)
    {
    }

    void Teach() const
    {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(const string &destination) const override
    {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

public:
    string Subject;
};

class Policeman : public People
{
public:
    Policeman(string name) : People("Policman", name)
    {
    }

    void Check(People &t) const
    {
        cout << "Policeman: " << Name << " checks " << t.type_() << ". " << t.type_() << "'s name is: " << t.Prof() << endl;
    }

    /*void Check(Student &s) const
    {
        cout << "Policeman: " << Name << " checks Student. Student's name is: " << s.Prof() << endl;
    }

    void Check(Policeman &p) const
    {
        cout << "Policeman: " << Name << " checks Policeman. Policeman's name is: " << p.Prof() << endl;
    }*/

    void Walk(const string &destination) const override
    {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }
};

void VisitPlaces(People &t, vector<string> places)
{
    for (auto p : places)
    {
        t.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});

    return 0;
}
