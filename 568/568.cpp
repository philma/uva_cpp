#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int clear(int& x, int factor)
{
    if(factor < 2)
        return 0;

    int cnt = 0;
    while(!(x % factor))
    {
        ++cnt;
        x /= factor;
    }

    return cnt;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        int ans = 1;
        if(n)
        {
            vector<int> numbers;
            int cnt_2 = 0, cnt_5 = 0;
            for(int i = 1; i <= n; ++i)
            {
                int x = i;
                cnt_2 += clear(x, 2);
                cnt_5 += clear(x, 5);
                numbers.push_back(x);
            }

            int factor = cnt_2 > cnt_5 ? 2 : 5;
            int cnt = cnt_2 > cnt_5 ? cnt_2 - cnt_5 : cnt_5 - cnt_2;
            for(auto i : numbers)
                ans = (ans * i) % 10;
            for(int i = 0; i < cnt; ++i)
                ans = (ans * factor) % 10;
        }

        cout << setw(5) << right << n;
        cout << left <<  " -> " << ans;
        cout << endl;
    }

    return 0;
}
