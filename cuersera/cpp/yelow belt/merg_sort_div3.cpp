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
    auto first_elem = elements.begin() + (elements.end() - elements.begin()) / 3;
    auto second_elem = elements.begin() + (elements.end() - elements.begin()) * 2 / 3;
    MergeSort(elements.begin(), first_elem);
    MergeSort(first_elem, second_elem);
    MergeSort(second_elem, elements.end());

    std::vector<typename RandomIt::value_type> temp;
    std::merge(elements.begin(), first_elem, first_elem, second_elem, std::back_inserter(temp));
    std::merge(temp.begin(), temp.end(), second_elem, elements.end(), range_begin);
}