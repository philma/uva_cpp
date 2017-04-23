#include <iostream>

using namespace std;

int main()
{
    uint32_t a = 0, b = 0;
    while(cin >> a >> b)
        cout << (a^b) << endl;

    return 0;
}
