#include <iostream>

using namespace std;

int sequence_len(long long n)
{
    int len = 0;
    do
    {
        ++len;
        if(n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }while(n > 1);

    return len;
}

int main()
{
    int lhs = 0, rhs = 0;
    while(cin >> lhs >> rhs && !(lhs == 0 && rhs == 0))
    {
        int min_value = lhs < rhs ? lhs : rhs;
        int max_value = lhs < rhs ? rhs : lhs;
        int ans = -1, number = 0;
        for(int i = min_value; i <= max_value; ++i)
        {
            int len = sequence_len(i);
            if(len > ans)
            {
                ans = len;
                number = i;
            }
        }

        cout << "Between " << min_value << " and " << max_value << ", ";
        cout << number << " generates the longest sequence of ";
        cout << ans << " values." << endl;
    }

    return 0;
}
