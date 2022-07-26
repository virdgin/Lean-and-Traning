#include <vector>
#include <iostream>
#include <algorithm>

void PrintVectorPart(const std::vector<int> &numbers);
void PrintVectorPart(const std::vector<int> &numbers)
{
    auto it = find_if(begin(numbers), end(numbers), [](const int &number)
                      { return number < 0; });
    for (auto i = it; i != numbers.begin();)
    {
        std::cout << *(--i) << " ";
    }
}