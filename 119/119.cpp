#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

struct CostInfo
{
    int money;
    set<string> friends;    
};

void parse_input(int num, vector<string>& names, map<string, CostInfo>& cost_infos)
{
        string line;
        getline(cin, line);

        stringstream ss_line(line);
        for(int i = 0; i < num; ++i)
        {
            string tmp;
            ss_line >> tmp;
            names.push_back(tmp);
        }

        for(int i = 0; i < num; ++i)
        {
            getline(cin, line);
            ss_line.clear();
            ss_line.str(line);
            
            string name;
            ss_line >> name;

            CostInfo cost_info;
            ss_line >> cost_info.money;
            int friend_num = 0;
            ss_line >> friend_num;
            for(int j = 0; j < friend_num; ++j)
            {
                string friend_name;
                ss_line >> friend_name;
                cost_info.friends.insert(friend_name);
            }

            cost_infos.insert(make_pair(name, cost_info));
        }
}

void output_result(const vector<string>& names, const map<string, CostInfo>& cost_infos)
{
    for(unsigned int i = 0; i < names.size(); ++i)
    {
        const string& name = names[i];
        const CostInfo& cost_info = cost_infos.find(name)->second;

        int cost = 0;
        if(!cost_info.friends.empty())
            cost = (cost_info.money / cost_info.friends.size()) * cost_info.friends.size();
        
        int recive = 0;
        for(auto it = cost_infos.begin(); it != cost_infos.end(); ++it)
        {
            if(it->second.friends.find(name) != it->second.friends.end())
                recive += it->second.money / it->second.friends.size();
        }

        cout << name << " " << recive - cost << endl;
    }
}

int main()
{
    int case_cnt = 0;
    int num = 0;
    while(cin >> num)
    {
        getchar();

        vector<string> names;
        map<string, CostInfo> cost_infos;
        parse_input(num, names, cost_infos);

        if(case_cnt) cout << endl;
        output_result(names, cost_infos);
        ++case_cnt;
    }

    return 0;
}