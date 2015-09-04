#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const string ALL_CASES[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
    string line;
    while(getline(cin, line))
    {
        stringstream input(line);
        vector<vector<int> > data(3, vector<int>(3, 0));
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                input >> data[i][j];
        
        int ans = 0;
        string ans_str;
        for(int i = 0; i < 6; ++i)
        {
            int sum = 0;
            for(int j = 0; j < 3; ++j)
            {
                if(ALL_CASES[i][j] == 'B')
                    sum += data[j][1] + data[j][2];
                else if(ALL_CASES[i][j] == 'C')
                    sum += data[j][0] + data[j][1];
                else
                    sum += data[j][0] + data[j][2];
            }

            if(i == 0 || sum < ans)
            {
                ans = sum;
                ans_str = ALL_CASES[i];
            }
        }

        cout << ans_str << ' ' << ans << endl;
    }

    return 0;
}
