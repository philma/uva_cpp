#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int ANS_NUM = 10;

bool is_square(long long x)
{
    long long tmp = sqrt(x);
    return tmp * tmp == x;
}

int main()
{
    int count = 0;
    for(long long i = 2; count < ANS_NUM; ++i)
    {
        long long tmp = (1 + i - 1) * (i - 1) / 2;
        long long x = (2 * i + 1) * (2 * i + 1) + 8 * tmp;
        long long y = static_cast<long long>(sqrt(x)) - 2 * i - 1;
        if(is_square(x) && y % 2 == 0)
        {
            cout << right << setw(10) << i;
            cout << right << setw(10) << i + y / 2 << endl;
            ++count;
        } 
    }

    return 0;
}
