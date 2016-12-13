#include <iostream>
#include <cmath>

using namespace std;

void position(int n, int& x, int& y)
{
    int tmp = static_cast<int>(sqrt(n));
    if(tmp * tmp == n)
    {
        x = tmp & 1 ? 1 : tmp;
        y = tmp & 1 ? tmp : 1;
    }
    else
    {
        int diff = n - tmp * tmp;
        tmp += 1;
        if(diff > tmp)
        {
            x = tmp & 1 ? tmp - (diff - tmp) : tmp;
            y = tmp & 1 ? tmp : tmp - (diff - tmp);
        }
        else
        {
            x = tmp & 1 ? tmp : diff;
            y = tmp & 1 ? diff : tmp;
        }
    }
}

int main()
{
    int n = 0;
    while(cin >> n && n)
    {
        int x = 0, y = 0;
        position(n, x, y);
        cout << x << ' ' << y << endl;
    }

    return 0;
}
