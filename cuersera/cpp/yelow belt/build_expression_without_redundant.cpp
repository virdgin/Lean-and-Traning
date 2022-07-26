#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;
struct Operation
{
    int number = 0;
    char operation = 0;
};
bool BracketNice(char last, char next)
{
    return (next == '*' || next == '/') && (last == '-' || last == '+');
}
int main()
{
    int number;
    char oper;
    cin >> number >> oper;
    vector<Operation> temp;
    for (int i = 0; i < oper; i++)
    {
        cin >> temp[i].operation >> temp[i].number;
    }
    deque<string> result;
    result.push_back(to_string(number));
    char prev_oper = oper;
    for (auto &o : temp)
    {
        if (BracketNice(prev_oper, oper))
        {
            result.push_front("(");
            result.push_back(")");
        }
        result.push_back(" ");
        result.push_back(string(1, o.operation));
        result.push_back(" ");
        result.push_back(to_string(o.number));
        prev_oper = o.operation;
    }
    for (auto &i : result)
    {
        cout << i;
    }
    /*
    string rul;
    int qualitty = 0;
    cin >> rul >> qualitty;
    string operation;
    string temp;
    stringstream result;
    result << rul;
    int bracket = 0;
    for (int i = 0; i < qualitty; i++)
    {
        string next_operation = operation;
        cin >> operation >> temp;
        if ((operation == "*" || operation == "/") && (next_operation == "-" || next_operation == "+"))
        {
            result << ")";
            bracket++;
        }
        result << " " << operation << " " << temp;
    }
    for (int i = bracket; i > 0; i--)
        cout << "(";
    cout << result.str();*/
    return 0;
}