/*Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. Сначала он хотел поставить им всем двойки, но в тот день профессор был добрым, а потому решил разделить студентов на две группы: списывающих и дающих списывать, и поставить двойки только первым.

У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на две группы так, чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    { 
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    queue<int> q;
    vector<int> col(n, -1);
    bool fl = true; 
    for (int start = 0; start < n; start++)
    { 
        if (col[start] == -1)
        { 
            col[start] = 0;
            q.push(start);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (auto u : g[v])
                {
                    if (col[u] == -1)
                    {
                        col[u] = 1 - col[v];
                        q.push(u);
                    }
                    else if (col[u] == col[v])
                    { 
                        fl = false;
                    }
                }
            }
        }
    }
    if (fl)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}