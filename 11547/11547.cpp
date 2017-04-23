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
        int x = (n*567/9.0+7492)*235/47-498;
        if(x < 0) x *= -1;
        cout << (x / 10 % 10) << endl;
    }

    return 0;
}
