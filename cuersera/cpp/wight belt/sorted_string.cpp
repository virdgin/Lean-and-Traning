class SortedStrings
{
public:
    void AddString(const string &s)
    {
        word.push_back(s); // добавить строку s в набор
    }
    vector<string> GetSortedStrings()
    {
        sort(begin(word), end(word));
        return word; // получить набор из всех добавленных строк в отсортированном порядке
    }

private:
    vector<string> word;
    // приватные поля
};