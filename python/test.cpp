#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> wb;
    vector<int> o;
    vector<int> r;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        wb.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        o.push_back(t);
    }
    for (size_t i = 1; i < wb.size(); i++)
    {
        if (wb[i - 1] - wb[i] > 0)
        {
            r.push_back(wb[i - 1] - wb[i]);
        }
    }
    r.push_back(wb[wb.size() - 1]);
    sort(r.begin(), r.end());
    sort(o.begin(), o.end());
    vector<int> k;
    int i = 0, j = 0;
    while (i < r.size())
    {
        if (j >= o.size())
        {
            i++;
            j = 0;
        }
        if (r[i] >= o[j])
        {
            k.push_back(i);
            o.erase(o.begin() + j);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout << k.size();
}
