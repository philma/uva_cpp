#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, max = -1, min = 100;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int x = 0;
            cin >> x;
            if(x > max) max = x;
            if(x < min) min = x;
        }

        cout << 2 * (max - min) << endl;
    }

    return 0;
}
