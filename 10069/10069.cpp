#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add(const string& num1, const string& num2, string& res)
{
    unsigned int len1 = num1.size();
    unsigned int len2 = num2.size();
    unsigned int res_len = len1 > len2 ? len1 : len2;
    res.resize(res_len);

    int carry = 0;
    for(unsigned int i = 0; i < res_len; ++i)
    {
        int b1 = i >= len1 ? 0 : num1[len1 - 1 - i] - '0';
        int b2 = i >= len2 ? 0 : num2[len2 - 1 - i] - '0';
        res[res_len - 1 - i] = '0' + (b1 + b2 + carry) % 10;
        carry = (b1 + b2 + carry) / 10;
    }

    if(carry)
        res.insert(0, 1, '0' + carry);
}

int main()
{
    int n = 0;
    cin >> n;
    getchar();
    while(n--)
    {
        string str_x;
        getline(cin, str_x);
        string str_z;
        getline(cin, str_z);

        vector<vector<int> > pos_info(str_z.size(), vector<int>());
        for(unsigned int i = 0; i < str_z.size(); ++i)
        {
            for(unsigned int j = 0; j < str_x.size(); ++j)
            {
                if(str_z[i] == str_x[j])
                    pos_info[i].push_back(j);
            }
        }

        vector<string> info(str_x.size(), "0");
        for(unsigned int i = 0; i < pos_info[0].size(); ++i)
            info[pos_info[0][i]] = "1";
        for(unsigned int i = 1; i < str_z.size(); ++i)
        {
            vector<string> tmp;
            for(unsigned int j = 0; j < pos_info[i].size(); ++j)
            {
                string cnt = "0";
                for(unsigned int k = 0; k < pos_info[i - 1].size(); ++k)
                {
                    if(pos_info[i - 1][k] >= pos_info[i][j])
                        break;
                    string res;
                    add(cnt, info[pos_info[i - 1][k]], res);
                    cnt = res;
                }
                tmp.push_back(cnt);
            }

            for(unsigned int j = 0; j < pos_info[i].size(); ++j)
                info[pos_info[i][j]] = tmp[j];
        }

        string ans = "0";
        for(unsigned int i = 0; i < pos_info[str_z.size() - 1].size(); ++i)
        {
            string res;
            add(ans, info[pos_info[str_z.size() - 1][i]], res);
            ans = res;
        }

        cout << ans << endl;
    }
    
    return 0;
}
