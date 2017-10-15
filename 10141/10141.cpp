#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>


using namespace std;

struct Proposal
{
    string name;
    double price;
    int met_num;
};

int main()
{
    int case_cnt = 0;
    int n = 0, p = 0;
    while(cin >> n >> p)
    {
        if(n == 0 && p == 0) break;

        ++case_cnt;

        getchar();
        string line;
        for(int i = 0; i < n; ++i)
            getline(cin, line);
        
        Proposal prop_need;
        for(int i = 0; i < p; ++i)
        {
            Proposal prop_tmp;
            getline(cin, prop_tmp.name);

            getline(cin, line);
            stringstream ss_line(line);
            ss_line >> prop_tmp.price >> prop_tmp.met_num;
            for(int j = 0; j < prop_tmp.met_num; ++j)
                getline(cin, line);
            
            if(i == 0 || prop_tmp.met_num > prop_need.met_num
                      || (prop_tmp.met_num == prop_need.met_num && prop_tmp.price < prop_need.price))
                prop_need = prop_tmp;
        }

        if(case_cnt > 1) cout << endl;
        cout << "RFP #" << case_cnt << endl;
        cout << prop_need.name << endl; 
    }

    return 0;
}