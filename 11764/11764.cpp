#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n = 0;
        cin >> n;

        int prev = 0;
        int taller = 0, shorter = 0;
        for(int j = 0; j < n; ++j)
        {
            int x = 0;
            cin >> x;
            if(prev)
            {
                if(prev < x)
                    ++taller;
                else if(prev > x)
                    ++shorter;
            }
            prev = x;
        }

        cout << "Case " << i + 1 << ":";
        cout << " " << taller << " " << shorter;
        cout << endl;
    }

    return 0;
}
