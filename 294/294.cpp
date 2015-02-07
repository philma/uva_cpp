#include <iostream>
#include <cmath>

using namespace std;

int divisor_num(int n)
{
    int count = 0, end = (int)(sqrt(n));
    for(int i = 1; i <= end; ++i)
    {
        if(n % i == 0)
            count += n/i == i ? 1 : 2;
    }

    return count;
}

int main()
{
    int n;

    cin >> n;
    while(n--)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        int lhs_tmp = lhs < rhs ? lhs : rhs;
        int rhs_tmp = lhs > rhs ? lhs : rhs;
        
        int number = 0, max_count = -1;
        for(int i = lhs_tmp; i <= rhs_tmp; ++i)
        {
            int tmp = divisor_num(i);
            if(tmp > max_count)
            {
                max_count = tmp;
                number = i;
            }
        }

        cout << "Between " << lhs_tmp << " and " << rhs_tmp << ", ";
        cout << number << " has a maximum of " << max_count << " divisors." << endl;
    }

    return 0;
}
