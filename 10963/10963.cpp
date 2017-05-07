#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int col_num = 0;
        cin >> col_num;

        int pre_dist = 0;
        bool ans = true;
        for(int j = 0; j < col_num; ++j)
        {
            int y1 = 0, y2 = 0;
            cin >> y1 >> y2;
            if(!ans) continue;

            if(j && y1 - y2 != pre_dist)
                ans = false;
            pre_dist = y1 - y2;
        }
        cout << (ans ? "yes" : "no") << endl;
        if(i < t - 1) cout << endl;
    }
    return 0;
}
