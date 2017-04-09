#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int case_num = 0;
    cin >> case_num;
    while(case_num--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        uint64_t dist = y - x;
        int step = 0;
        if(dist)
        { 
            int n = (sqrt(4 * dist + 1) - 1) / 2; 
            step = 2 * n;

            int sum = (1 + n) * n;
            int diff = dist - sum;
            if(diff > 0 && diff < n + 2)
                step += 1;
            else if(diff >= n + 2)
                step += 2;
        }
        cout << step << endl;
    }

    return 0;
}
