#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

void split(const string& src_str, const string& delimiter
        , vector<string>& sub_strs)
{
    size_t pos = 0, begin = 0;
    while((pos = src_str.find(delimiter, begin)) 
            != string::npos)
    {
        sub_strs.push_back(src_str.substr(begin, pos - begin));
        begin = pos + delimiter.size();
    }

    if(begin < src_str.size())
        sub_strs.push_back(src_str.substr(begin));
}

int main()
{
    string line;
    getline(cin, line);
    int case_num = atoi(line.c_str());
    while(case_num--)
    {
        getline(cin, line);

        getline(cin, line);
        vector<string> sub_strs;
        split(line, " ", sub_strs);

        vector<int> indexs;
        for(auto& str : sub_strs)
            indexs.push_back(atoi(str.c_str()));

        getline(cin, line);
        sub_strs.clear();
        split(line, " ", sub_strs);

        vector<string> ans(indexs.size(), "");
        for(int i = 0; i < indexs.size(); ++i)
            ans[indexs[i] - 1] = sub_strs[i];

        for(auto& str : ans)
            cout << str << endl;
        if(case_num) cout << endl;
    }

    return 0;
}
