/*
Реализуйте систему ведения личного бюджета. Вам необходимо обрабатывать запросы следующих типов:

ComputeIncome from to: вычислить чистую прибыль за данный диапазон дат.

Earn from to value: учесть, что за указанный период (равномерно по дням) была заработана сумма value.

Примечания:

Во всех диапазонах from to обе даты from и to включаются.

Формат ввода
В первой строке вводится количество запросов Q, затем в описанном выше формате вводятся сами запросы,
по одному на строке.

Формат вывода
Для каждого запроса ComputeIncome в отдельной строке выведите вещественное число — прибыль за
 указанный диапазон дат.

Примечание:

используйте std::сout.precision(25)  в вашем коде для единообразия формата вывода вещественных чисел

Ограничения
Количество запросов Q — натуральное число, не превышающее 50.

Все даты вводятся в формате YYYY-MM-DD. Даты корректны (с учётом високосных годов)
и принадлежат интервалу с 2000 до 2099 гг.

value — положительные целые числа, не превышающие 1000000.

1 секунда на обработку всех запросов.
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <numeric>
#include <chrono>

using namespace std;
pair<string, string> SplitTwoString(string s, string delimeter)
{
    const size_t pos = s.find(delimeter);
    if (pos == s.npos)
    {
        return {s, ""};
    }
    else
    {
        return {s.substr(0, pos), s.substr(pos + delimeter.length())};
    }
}
pair<string, string> SplitTwo(string s, string delimiter)
{
    const auto [lhs, rhs] = SplitTwoString(s, delimiter);
    return {lhs, rhs};
}
string Token(string &str, string delimiter = " ")
{
    const auto [lhs, rhs] = SplitTwo(str, delimiter);
    str = rhs;
    return lhs;
}
int InToString(string str)
{
    size_t pos;
    const int res = stoi(string(str), &pos);
    if (pos != str.length())
    {
        stringstream error;
        error << "string" << str << " contains " << (str.length() - pos) << " trailling chars";
        throw invalid_argument(error.str());
    }
    return res;
}
class Date
{
private:
    int year;
    int month;
    int day;

public:
    static Date FromString(string str)
    {
        const int _year = InToString(Token(str, "-"));
        const int _month = InToString(Token(str, "-"));
        const int _day = InToString(str);
        return {_year, _month, _day};
    }
    time_t AsTimestamp() const
    {
        tm t;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_mday = day;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;
        t.tm_isdst = 0;
        return mktime(&t);
    }
    Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day){};
};
int DaysDiff(const Date &to, const Date &from)
{
    const time_t timestamp_to = to.AsTimestamp();
    const time_t timestamp_from = from.AsTimestamp();
    static constexpr int SECOND_IN_DAY = 60 * 60 * 24;
    return (timestamp_to - timestamp_from) / SECOND_IN_DAY;
}

static const Date START_DATE = Date::FromString("1700-01-01");
static const Date END_DATE = Date::FromString("2100-01-01");
static const size_t DAY_COUNT = DaysDiff(END_DATE, START_DATE);

int main()
{
    cout.precision(25);
    vector<uint64_t> money(DAY_COUNT, .0);
    vector<uint64_t> partial_sums(DAY_COUNT, 0);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        uint64_t cash;
        string value;
        cin >> value >> cash;
        Date date_value = Date::FromString(value);
        auto mon = DaysDiff(date_value, START_DATE);
        money[mon] = cash;
    }
    partial_sum(money.begin(), money.end(), partial_sums.begin());
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string Dfrom, Dto;
        cin >> Dfrom >> Dto;
        Date from = Date::FromString(Dfrom);
        Date to = Date::FromString(Dto);
        auto start = DaysDiff(from, START_DATE);
        auto finish = DaysDiff(to, START_DATE);
        if (start > 0)
        {
            cout << partial_sums[finish] - partial_sums[start - 1] << endl;
        }
        else
        {
            cout << partial_sums[finish] << endl;
        }
    }
    return 0;
}