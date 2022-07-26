#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>

size_t fac(size_t qwe);

std::ostream &operator<<(std::ostream &out, const std::vector<size_t> &vec);

void exec_task(std::vector<size_t> &vec)
{
    size_t counter = fac(vec.size());

    for (size_t i = 0; i < counter; i++)
    {
        std::prev_permutation(vec.begin(), vec.end());
        std::cout << vec << std::endl;
    }
}

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<size_t> vec;

    for (size_t i = 1; i <= N; i++)
    {
        vec.push_back(i);
    }

    exec_task(vec);

    return 0;
}

size_t fac(size_t qwe)
{
    if (qwe == 0)
        return 1;
    else
        return qwe * fac(qwe - 1);
}

std::ostream &operator<<(std::ostream &out, const std::vector<size_t> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        out << vec[i] << ' ';
    }
    return out;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int range_length;
  cin >> range_length;
  vector<int> permutation(range_length);
  
  // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
  // Заполняет диапазон последовательно возрастающими значениями
  // Обратные итераторы позволяют заполнить его, двигаясь от конца к началу
  iota(permutation.rbegin(), permutation.rend(), 1); 
  
  // prev_permutation ->
  //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
  // Преобразует диапазон в предыдущую (лексикографически) перестановку,
  // если она существует, и возвращает true,
  // иначе (если не существует) - в последнюю (наибольшую) и возвращает false
  do {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  } while (prev_permutation(permutation.begin(), permutation.end()));

  return 0;
}*/
