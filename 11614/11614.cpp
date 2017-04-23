#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        uint64_t n = 0;
        cin >> n;
        n = (sqrt(1 + 8 * n) - 1) / 2;
        cout << n << endl;
    }

    return 0;
}
