#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int k = 0;
        cin >> k;

        int x = sqrt(k);
        vector<int> factors;
        for(int j = 2; j <= x; ++j)
        {
            if(k % j == 0)
            {
                factors.push_back(j);
                if(factors.size() >= 2)
                    break;
            }
        }

        cout << "Case #" << i + 1;
        cout << ": " << k;
        for(auto j: factors)
            cout << " = " << j << " * " << k / j;
        cout << endl;
    }

    return 0;
}
