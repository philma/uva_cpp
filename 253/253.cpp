#include <iostream>
#include <string>
#include <set>

using namespace std;

void dfs(const string& str, const string& dst, set<string>& sset, bool& meet)
{
    int pos_map[6][6] = {{2, 1, 5, 0, 4, 3}, {3, 1, 0, 5, 4, 2},
                         {4, 0, 2, 3, 5, 1}, {1, 5, 2, 3, 0, 4},
                         {0, 3, 1, 4, 2, 5}, {0, 2, 4, 1, 3, 5}};
    for(int i = 0; i < 6; ++i)
    {
        string next_str;
        for(int j = 0; j < 6; ++j)
            next_str.push_back(str[pos_map[i][j]]);

        if(next_str == dst)
        {
            meet = true;
            return ;
        }

        if(sset.find(next_str) == sset.end())
        {
            sset.insert(next_str);
            dfs(next_str, dst, sset, meet);
            if(meet) return ;
        }
    }
}

bool is_same(const string& src, const string& dst)
{
    set<string> sset;
    bool meet = false;

    dfs(src, dst, sset, meet);

    return meet;
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        string src = line.substr(0, 6);
        string dst = line.substr(6);
        if(is_same(src, dst))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

    return 0;
}
