#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix)
{
    string f_p = string();
    string s_p = string();
    f_p.push_back();
    s_p.push_back();
    return make_pair(lower_bound(range_begin, range_end, f_p),
                     lower_bound(range_begin, range_end, s_p));
}