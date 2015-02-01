#include <iostream>

using namespace std;

static const int MAX_N = 1000000;
int cycle[MAX_N + 1];

void init(int* cycle)
{
    for(int i = 1; i <= MAX_N; ++i)
      cycle[i] = -1;

    for(int i = 1; i <= MAX_N; ++i)
    {
        long long x = i;
        int count = 1;
        while(x != 1)
        {
            if(x & 1)
            {
                if(3 * x + 1 > MAX_N || cycle[3 * x + 1] == -1)
                {
                    ++count;
                    x = 3 * x + 1;
                }
                else
                {
                    count += cycle[3 * x + 1];
                    break;
                }
            }
            else
            {
                if(x / 2 > MAX_N || cycle[x / 2] == -1)
                {
                    ++count;
                    x /= 2;
                }
                else
                {
                    count += cycle[x / 2];
                    break;
                }
            }
        }

        cycle[i] = count;
    }
}

int main()
{
    init(cycle);

    int lhs = 0, rhs = 0;
    while(cin >> lhs >> rhs)
    {
        int lhs_tmp = lhs < rhs ? lhs : rhs;
        int rhs_tmp = lhs > rhs ? lhs : rhs;

        int ans = -1;
        for(int i = lhs_tmp; i <= rhs_tmp; ++i)
        {
            if(cycle[i] > ans)
              ans = cycle[i];
        }

        cout << lhs << " " << rhs << " " << ans << endl;
    }

    return 0;
}
