#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        double d = 0, v = 0, u = 0;
        cin >> d >> v >> u;
        cout << "Case " << i + 1 << ": ";
        if(!(u > 0 && v > 0 && u > v))
            cout << "can't determine";
        else
        {
            double ans = d / sqrt(u * u - v * v) - (d / u);
            cout << fixed << setprecision(3) << ans;
        }
        cout << endl;
    }

    return 0;
}
