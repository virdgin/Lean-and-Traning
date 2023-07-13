#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    string s, l;
    cin >> s;
    if (n >= s.size())
    {
        count = s.size();
    }
    else
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            int r = 0, t = 0;
            char d = s[i];
            if (l.find(d) == l.npos)
            {
                l = l + d;
                for (int j = 0; j < s.size() - 1; j++)
                {
                    while (t <= n)
                    {
                        if (r == s.size() + 1)
                            break;
                        if (s[r] == d)
                        {
                            r++;
                        }
                        else
                        {
                            r++;
                            t++;
                        }
                    }
                    if (r - j - 1 > count)
                        count = r - j - 1;
                    if (s[j] != d)
                        t--;
                }
            }
        }
    }
    cout << count;
}
