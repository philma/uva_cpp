#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(auto i = 0; i < t; ++i)
    {
        int n = 0, k = 0, p = 0;
        cin >> n >> k >> p;

        cout << "Case " << i + 1 << ": ";
        int ans = (k + p) % n;
        cout << (ans ? ans : n) << endl; 
    }

    return 0;
}
