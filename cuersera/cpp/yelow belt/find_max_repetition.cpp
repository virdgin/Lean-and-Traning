#include <map>
#include <tuple>
#include <vector>
using namespace std;
int FindMaxRepetitionCount(const vector<Region> &regions)
{
    int result = 0;
    map<Region, int> countries;
    for (const auto &i : regions)
    {
        result = max(result, ++countries[i]);
    }
    return result;
}
bool operator<(const Region &lhs, const Region &rhs)
{
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}