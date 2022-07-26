#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;
template <typename T>
T Sqr(const T &I);
template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &P);
template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &M);
template <typename T>
vector<T> Sqr(const vector<T> &V);
template <typename T>
T Sqr(const T &I)
{
    return I * I;
}
template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &P)
{
    return {Sqr(P.first), Sqr(P.second)};
}
template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &M)
{
    map<Key, Value> R;
    for (const auto &key : M)
    {
        R[key.first] = Sqr(key.second);
    }
    return R;
}
template <typename T>
vector<T> Sqr(const vector<T> &V)
{
    vector<T> R;
    for (const T &i : V)
    {
        R.push_back(Sqr(i));
    }
    return R;
}
