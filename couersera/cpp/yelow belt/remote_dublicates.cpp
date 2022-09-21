#include <algorithm>
#include <vector>
using namespace std;
template <typename T>
void RemoveDuplicates(vector<T> &elements)
{
    sort(elements.begin(), elements.end());
    auto it = unique(begin(elements), end(elements));
    elements.erase(it, end(elements));
}