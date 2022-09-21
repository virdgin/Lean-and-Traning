#include <iostream>
using namespace std;

int main()
{
    unsigned n;
    uint16_t r;

    cin >> n >> r;

    uint64_t sum = 0;
    uint32_t w, h, d;
    uint64_t tmp_sum = 1;

    for (unsigned i = 0; i < n; ++i)
    {
        cin >> w >> h >> d;

        tmp_sum = 1;

        tmp_sum *= w;
        tmp_sum *= h;
        tmp_sum *= d;

        sum += tmp_sum;
    }

    sum *= r;

    cout << sum;
    return 0;
}