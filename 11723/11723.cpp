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
        cout << "Case "
             << t
             << ": ";

        int x = r / n;
        int tmp = r % n;
        if(x < 27 || (x == 27 && tmp == 0))
            cout << (tmp ? x : x - 1);
        else
            cout << "impossible";
        cout << endl;
    }

    return 0;
}
