#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string &prefix)
{
    string f_p = string(prefix);
    string s_p = string(prefix);
    s_p[s_p.size() - 1]++;
    return make_pair(lower_bound(range_begin, range_end, f_p),
                     lower_bound(range_begin, range_end, s_p));
}