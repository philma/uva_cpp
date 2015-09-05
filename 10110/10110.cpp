#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int n = 0;
    while(cin >> n && n)
    {
        unsigned int tmp = static_cast<unsigned int>(sqrt(n));
        cout << (tmp * tmp == n ? "yes" : "no") << endl;
    }

    return 0;
}
