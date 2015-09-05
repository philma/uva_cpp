#include <iostream>
#include <cmath>

using namespace std;

bool is_composite(int x)
{
    bool prime = true;
    int tmp = static_cast<int>(sqrt(x));
    for(int i = 2; i <= tmp; ++i)
    {
        if(x % i == 0)
        {
            prime = false;
            break;
        }
    }

    return (prime ? false : true);
}

unsigned int Mod(unsigned int x, unsigned int y, unsigned int n)
{
    unsigned int ans = 1;
    for(; y; y /= 2)
    {
        if(y & 1)
            ans = (ans * x) % n;
        x = (x * x) % n;
    }

    return ans;
}

bool is_carmichael(int n)
{
    if(!is_composite(n)) return false;

    bool carmichael = true;
    for(unsigned int i = 2; i < n; ++i)
    {
        if(Mod(i, n, n) != i)
        {
            carmichael = false;
            break;
        }
    }

    return carmichael;
}

int main()
{
    unsigned int n = 0;
    while(cin >> n && n)
    {
        if(is_carmichael(n))
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;
    }

    return 0;
}
