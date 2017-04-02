#include <iostream>
#include <cmath>

using namespace std;

int caculate_min_n(int k)
{
    if(k == 0) return 3;

    int n = (sqrt(8 * static_cast<long long>(k) + 1) - 1) / 2;
    int sum = (1 + n) * n / 2;

    if(sum == k)
        return n;
    else
    {
        int tmp = sum + n + 1;
        if((tmp - k) % 2 == 0)
            return n + 1;
        else
        {
            if((n + 2) % 2 == 0)
                return n + 3;
            else
                return n + 2;
        }
    }
}

int main()
{
    int case_num = 0;
    cin >> case_num;
    while(case_num--)
    {
        int k = 0;
        cin >> k;

        cout << caculate_min_n(k < 0 ? -k : k)
             << endl;
        if(case_num) cout << endl;
    }

    return 0;
}
