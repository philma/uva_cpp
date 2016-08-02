#include <iostream>

using namespace std;

int main()
{
    int a = 0, limit = 0;
    int cases = 0;
    while(cin >> a >> limit && 
            !(a < 0 && limit < 0))
    {
        ++cases;

        int64_t tmp = a;
        int times = 0;
        while(tmp <= limit)
        {
            ++times;
            if(tmp == 1) break;
            if(tmp & 1)
                tmp = tmp * 3 + 1;
            else
                tmp /= 2;
        }

        cout << "Case " << cases << ": A = "
             << a << ", limit = " << limit
             << ", number of terms = " << times 
             << endl;
    }

    return 0;
}
