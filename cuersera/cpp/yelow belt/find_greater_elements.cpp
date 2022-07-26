#include <set>
#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T> &elements, const T &border)
{
    std::vector<T>result;
    /* // Начнём итерироваться по множеству
    auto it = begin(elements);
    // Цель — найти первый элемент, больший border
    // Если итератор не достиг конца и указывает не туда, двигаем
    while (it != end(elements) && *it <= border) {
      ++it;
    }
    // Возвращаем вектор, созданный из элементов множества, начиная с it
    return {it, end(elements)};

      */

    for (auto i : elements)
    {
        if (i > border)
            result.push_back(i);
    }
    std::sort(result.begin(), result.end());
    return result;
}
