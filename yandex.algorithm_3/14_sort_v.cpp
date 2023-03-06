#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> s;
queue<int> op;

int main()
{
    int n;
    cin >> n;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (!s.empty() && val > s.top())
        {
            cout << "NO";
            return 0;
        }
        op.push(1);
        s.push(val);
        while (!s.empty() && s.top() == num)
        {
            op.push(2);
            s.pop();
            num++;
        }
    }
    cout << "YES";
    return 0;
}