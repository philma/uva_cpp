#include <iostream>

using namespace std;

int main()
{
    int r = 0, n = 0;
    int t = 0;
    while(cin >> r >> n
            && r && n)
    {
        ++t;
        int x = r / n;
        int tmp = r % n;
        int ans = 0;
        if(x < 27 || (x == 27 && tmp == 0))
            ans = tmp ? x : x - 1;
        else
            ans = -1;

        cout << "Case "
             << t
             << ": ";
        if(ans == -1)
            cout << "impossible";
        else
            cout << ans;
        cout << endl;
    }

    return 0;
}
