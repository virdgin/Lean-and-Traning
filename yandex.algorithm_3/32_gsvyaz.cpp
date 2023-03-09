#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> connectedComponents(const vector<vector<int>> &a)
{
    int n = a.size();
    vector<bool> mark(n, false);
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i)
    {
        if (mark[i] == false)
        {
            mark[i] = true;
            vector<int> cur;
            cur.push_back(i);
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i = 0; i < a[x].size(); ++i)
                {
                    int c = a[x][i];
                    if (mark[c])
                    {
                        continue;
                    }
                    mark[c] = true;
                    q.push(c);
                    cur.push_back(c);
                }
            }
            res.push_back(cur);
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    auto r = connectedComponents(a);
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); ++i)
    {
        cout << r[i].size() << endl;
        for (int j = 0; j < r[i].size(); ++j)
        {
            cout << r[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}