#include <iostream>

using namespace std;

int main()
{
    int n = 0, c = 0;
    while(cin >> n && n)
    {
        ++c;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = 0;
            cin >> x;
            if(x) ++cnt;
        }
        cout << "Case " << c << ": ";
        cout << cnt - (n - cnt) << endl;
    }
    return 0;
}
