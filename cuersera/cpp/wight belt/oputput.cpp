#include <iostream>
#include <string>
#include <fstream> //для работы с файлами
#include <iomanip>
using namespace std;
int main()
{
    ifstream input("input.txt");             // открытие файла на чтение
    ofstream output("output.txt", ios::app); //дозапись
    string line;
    if (input) //проверка на наличие файла
    {
        while (getline(input, line)) //чтение в переменную стринг
        {

            output << line << endl; //вывод в файл
        }
    }

    return 0;
}