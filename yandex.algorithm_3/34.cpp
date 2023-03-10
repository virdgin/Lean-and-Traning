#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n, m; // n-количество вершин, m-количество ребер
vector<vector<int>> a;
vector<int> colors; // Массив цветов вершин, 0 - белый, 1 - серый, 2 - черный
stack<int> st;      // Стек для вершин
bool error = false; // Переменная которая равна true если нельзя выполнить топ. сортировку графа

void dfs(const int &v) // Поиск в глубину
{
    if (error)
        return;
    colors[v] = 1; // При входе в вершину окрашиваем ее в серый цвет
    for (int i = 0; i < a[v].size(); i++)
        if (colors[a[v][i]] == 0)
            dfs(a[v][i]);
        else                          // Если не были в вершине то заходим нее
            if (colors[a[v][i]] == 1) // Если мы пытаемся зайти в серую вершину то это цикл
            {
                error = true;
                return;
            }
    st.push(v);
    colors[v] = 2; // При выходе из вершины окрашиваем ее в черный цвет
}

int main()
{
    // Ввод
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        a.push_back(vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
    }
    colors.resize(n);

    for (int i = 0; i < n; i++)
        colors[i] = 0; // Сначала все вершины покрасим в белый цвет

    for (int i = 0; i < n; i++)
        if (!colors[i])
            dfs(i);

    // Вывод
    if (error)
        cout << -1;
    else
        while (!st.empty())
        {
            cout << st.top() + 1 << " ";
            st.pop();
        }
}