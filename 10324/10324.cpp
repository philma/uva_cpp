#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void parse_str(const string& line, vector<pair<int, int>>& info)
{
    int pos = 0;
    char c = line[0];

    for(int i = 1; i < line.size(); ++i)
    {
        if(line[i] == c) 
            continue;
        else
        {
            info.push_back(make_pair(pos, i - 1));
            pos = i;
            c = line[pos];
        }
    }

    info.push_back(make_pair(pos, line.size() - 1));
}

bool judge_interval(const vector<pair<int,int>>& info, const pair<int, int>& interval)
{
    int low = 0, high = info.size() - 1;
    int pos = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(interval.first >= info[mid].first)
        {
            pos = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return interval.second <= info[pos].second;
}

int main()
{
    int case_cnt = 0;
    string line;
    while(getline(cin, line) && line != "")
    {
        ++case_cnt;

        vector<pair<int, int>> info;
        parse_str(line, info);

        int query_num = 0;
        cin >> query_num;
        cout << "Case " << case_cnt << ":" << endl;
        for(int i = 0; i < query_num; ++i)
        {
            int begin = 0, end = 0;
            cin >> begin >> end;
            bool same = judge_interval(info, make_pair(min(begin, end), max(begin, end)));
            cout << (same ? "Yes" : "No") << endl;
        }
        getchar();
    }

    return 0;
}