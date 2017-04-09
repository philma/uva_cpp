#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int64_t n = 0;
    while(cin >> n && n > 0)
    {
        int64_t profit = 0;
        if(n > 1)
            profit = round(100 * n / 4);
        cout << profit << '%' << endl;
    }

    return 0;
}
