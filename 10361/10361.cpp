#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        for(size_t j = 0; j < line1.size(); ++j)
        {
            if(line1[j] == '<' || line1[j] == '>')
            {
                if(line1[j] == '>')
                    line1[j] = '<';
                continue;
            }
            else
                cout << line1[j];
        }
        cout << endl;

        vector<string> sub_strs;
        for(int j = 0; j < 5; ++j)
        {
            size_t pos = line1.find_first_of('<');
            if(pos == string::npos)
                sub_strs.push_back(line1);
            else
            {
                sub_strs.push_back(line1.substr(0, pos));
                line1 = line1.substr(pos + 1);
            }
        }

        for(size_t j = 0; j < line2.size(); ++j)
        {
            if(line2[j] == '.') break;
            cout << line2[j];
        }
        cout << sub_strs[3] << sub_strs[2]
             << sub_strs[1] << sub_strs[4] << endl;
    }

    return 0;
}
