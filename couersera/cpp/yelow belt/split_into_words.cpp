#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
std::vector<std::string> SplitIntoWords(const std::string &s)
{
    auto start_it = begin(s);
    auto end_it = end(s);
    std::vector<std::string> result;
    while (true)
    {
        auto it = std::find(start_it, end_it, ' ');
        result.push_back(std::string(start_it, it));
        if (it == end_it)
        {
            break;
        }
        else
        {
            start_it = it + 1;
        }
    }
    /*std::string t1 = s + " ";
    std::string temp;
    while (it != t1.end())
    {
        if (*it != ' ')
        {
            temp += *it;
        }
        else
        {
            result.push_back(temp);
            temp = "";
        }
        ++it;
    }*/
    return result;
}

int main()
{
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it)
    {
        if (it != begin(words))
        {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}