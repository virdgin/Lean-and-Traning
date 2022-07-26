/*
Напишите функцию FindNearestElement, для множества целых чисел numbers и
данного числа border возвращающую итератор на элемент множества, ближайший к
border.
Если ближайших элементов несколько, верните итератор на наименьший из них.
*/
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int> &numbers,
    int border);

set<int>::const_iterator FindNearestElement(
    const set<int> &numbers,
    int border)
{
    auto first_el = numbers.lower_bound(border);
    if (first_el == numbers.begin())
        return first_el;
    auto another_el = prev(first_el);
    if (first_el == numbers.end())
        return another_el;
    bool result = (border - *another_el <= *first_el - border);
    return (result) ? another_el : first_el;
}
/*int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
*/