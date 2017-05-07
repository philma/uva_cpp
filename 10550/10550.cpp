#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> pos(4, 0);
    while(true)
    {
        bool zero_all = true;
        for(auto& val : pos)
        {
            cin >> val;
            if(val) zero_all = false;
        }
        if(zero_all) break;

        auto distance = [](int x, int y, int direct){
            if(direct)
                return (x > y ? 40 - x + y : y - x);
            else
                return (x < y ? 40 - y + x : x - y);
        };
        int ans = 120;
        ans += distance(pos[0], pos[1], 0);
        ans += distance(pos[1], pos[2], 1);
        ans += distance(pos[2], pos[3], 0);
        cout << 9 * ans << endl;
    }

    return 0;
}
