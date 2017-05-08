#include <iostream>

using namespace std;

int main()
{
    int n = 0, budget = 0;
    int h = 0, w = 0;
    while(cin >> n >> budget >> h >> w)
    {
        int cost = 0;
        for(int i = 0; i < h; ++i)
        {
            int price = 0;
            cin >> price;

            bool bed_enough = false;
            for(int j = 0; j < w; ++j)
            {
                int bed = 0;
                cin >> bed;
                if(bed >= n) bed_enough = true;
            }

            int total = price * n;
            if(bed_enough && total <= budget
                    && (cost == 0 || total < cost))
                cost = total;
        }

        if(cost)
            cout << cost << endl;
        else
            cout << "stay home" << endl;
    }

    return 0;
}
