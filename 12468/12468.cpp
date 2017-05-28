#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    while(cin >> a >> b
            && !(a == -1 && b == -1))
    {
        int max_v = a > b ? a : b;
        int min_v = a < b ? a : b;
        int ans = max_v - min_v;
        cout << (ans > 50 ? 100 - ans : ans) << endl;
    }

    return 0;
}
