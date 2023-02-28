/*Научитесь пользоваться стандартной структурой данных stack для целых чисел. Напишите программу, содержащую описание стека и моделирующую работу стека, реализовав все указанные здесь методы. Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После выполнения каждой команды программа должна вывести одну строчку. Возможные команды для программы:

push n
Добавить в стек число n (значение n задается после команды). Программа должна вывести ok.

pop
Удалить из стека последний элемент. Программа должна вывести его значение.

back
Программа должна вывести значение последнего элемента, не удаляя его из стека.

size
Программа должна вывести количество элементов в стеке.

clear
Программа должна очистить стек и вывести ok.

exit
Программа должна вывести bye и завершить работу.

Перед исполнением операций back и pop программа должна проверять, содержится ли в стеке хотя бы один элемент. Если во входных данных встречается операция back или pop, и при этом стек пуст, то программа должна вместо числового значения вывести строку error.*/
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> r;
    int x = 0;
    std::string command;
    std::cin >> command;
    while (command != "exit")
    {
        if (command == "push")
        {
            std::cin >> x;
            r.push_back(x);
            std::cout << "ok" << std::endl;
        }
        else if (command == "pop")
        {
            if (r.size() > 0)
            {
                std::cout << r[r.size() - 1] << std::endl;
                r.pop_back();
            }
            else
            {
                std::cout << "error" << std::endl;
            }
        }
        else if (command == "back")
        {
            if (r.size() > 0)
            {
                std::cout << r[r.size() - 1] << std::endl;
            }
            else
            {
                std::cout << "error" << std::endl;
            }
        }
        else if (command == "size")
        {
            std::cout << r.size() << std::endl;
        }
        else if (command == "clear")
        {
            r.clear();
            std::cout << "ok" << std::endl;
        }
        std::cin >> command;
    }
    std::cout << "bye" << std::endl;
}