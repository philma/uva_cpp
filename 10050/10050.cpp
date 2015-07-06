#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, p = 0;
        cin >> n >> p;
        vector<int> party;
        for(int i = 0; i < p; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            party.push_back(tmp);
        }

        vector<int> days(n, 0);
        for(unsigned int i = 0; i < party.size(); ++i)
        {
            int h = party[i];
            for(unsigned int j = h - 1; j < days.size(); j += h)
            {
                if((j % 7) == 5 || (j % 7) == 6)
                    continue;
                days[j] = 1;
            }
        }

        cout << count(days.begin(), days.end(), 1) << endl;
    }

    return 0;
}
