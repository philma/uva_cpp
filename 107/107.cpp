#include <iostream>
#include <cmath>

using namespace std;

int power(int a, int b)
{
    int ans = 1;
    for(; b; b >>= 1)
    {
        if (b & 1)  ans *= a;
        a *= a;
    }

    return ans;
}

bool check(int x, int n, int& k)
{
    if(n == 0 || n == 1) return false;

    k = 0;
    while(!(x % n))
    {
        x /= n ;
        ++k;
    }

    if(x != 1) return false;

    return true;
}

void find_n(int x, int y, int& n, int& k)
{
    if(y == 1)
    {
        n = 1;
        check(x, n + 1, k);
    }
    else
    {
        int up_limit = static_cast<int>(sqrt(y - 1));
        for(int i = 1; i <= up_limit; ++i)
        {
            if((y - 1) % i != 0) continue;

            if(check(y, i + 1, k) && power(i + 2, k) == x)
            {
                n = i + 1;
                return ;
            }

            if((y - 1) / i != i)
            {
                int tmp = (y - 1) / i;
                if(check(y, tmp + 1, k) && power(tmp + 2, k) == x)
                {
                    n = tmp + 1;
                    return ;
                }
            }
        }
    }

    return ;
}

int calc_ans1(int n, int k)
{
    int ans = 0;
    for(int i = 0; i < k; ++i)
        ans += power(n, i);

    return ans;
}

int calc_ans2(int n, int k)
{
    int ans = 0;
    for(int i = 0; i <= k; ++i)
        ans += power(n + 1, k - i) * power(n, i);

    return ans;
}

int main()
{
    int x = 0, y = 0;

    while(cin >> x >> y)
    {
        if(x == 0 && y == 0)
            break;

        int n = 0, k = 0;
        find_n(x, y, n, k);

        cout << calc_ans1(n, k) << " " << calc_ans2(n, k) << endl;
    }

    return 0;
}
