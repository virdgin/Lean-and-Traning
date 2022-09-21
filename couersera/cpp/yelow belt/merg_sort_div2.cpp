#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin < 2)
        return;
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    MergeSort(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 2);
    MergeSort(elements.begin() + (elements.end() - elements.begin()) / 2, elements.end());
    std::merge(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 2, elements.begin() + (elements.end() - elements.begin()) / 2, elements.end(), range_begin);
}