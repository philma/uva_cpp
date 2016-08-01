#include <iostream>

using namespace std;

int main()
{
    int64_t a = 0, b = 0;
    while(cin >> a >> b)
    {
        a -= b;
        if(a < 0) a *= -1;
        cout << a << endl;
    }

    return 0;
}
