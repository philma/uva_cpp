#include <iostream>
#include <vector>

using namespace std;

int find_ans(int k)
{
    for(int m = k + 1; ; ++m)
    {
        long long number = 0;
        for(int i = 1;i <= 2*k; ++i)
        {
            long long bit_pos = 4*k - 2*(i - 1);
            number |= (static_cast<long long>(1) << (bit_pos - 1));
            if(i > k)
                number |= (static_cast<long long>(1) << (bit_pos - 2));
        }
        int count_good = k, count_bad = k;

        int pos = 0;
        while(count_bad > 0 && count_good == k)
        {
            pos = (pos + m - 1) % (count_good + count_bad);
            long long bit_pos = 2 * (count_good + count_bad) - 2 * pos;
            bool over_k = (number >> (bit_pos - 2) & 1) ? true : false;
            number = (number & ((static_cast<long long>(1) << (bit_pos - 2)) - 1)) + (number >> bit_pos << (bit_pos - 2));
            if(over_k)
                --count_bad;
            else
                --count_good;

            if(pos >= (count_bad + count_good))
                pos = 0;
        }

        if(count_bad == 0 && count_good == k)
            return m;
    }

    return 0;
}

int main()
{
    vector<int> ans;
    for(int i = 1; i <= 13; ++i)
        ans.push_back(find_ans(i));

    int k = 0;
    while(cin >> k && k != 0)
    {
        cout << ans[k - 1] << endl;
    }

    return 0;
}
