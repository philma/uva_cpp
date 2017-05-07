#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using PairType = pair<int,int>;
using VectorType = vector<PairType>;

void judge(int stick_ori
        , VectorType& sticks, int index, int stick_use, int sum
        , bool& match)
{
    if(sum == stick_ori)
    {
        if(stick_use == sticks.size())
        {
            match = true;
            return;
        }
        sum = 0;
        index = 0;
    }

    for(int i = index; i < sticks.size(); ++i)
    {
        if(sticks[i].second) continue;
        if(sticks[i].first + sum > stick_ori) continue;

        sticks[i].second = 1;
        judge(stick_ori
                , sticks, i + 1, stick_use + 1, sum + sticks[i].first
                , match);
        if(match) return ;

        sticks[i].second = 0;

        if(sum == 0) break;
        while(i < sticks.size() - 1 
                && sticks[i].first == sticks[i + 1].first)
            ++i;
    }
}

int main()
{
    int n = 0;
    while(cin >> n && n)
    {
        VectorType sticks;
        int stick_sum = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = 0;
            cin >> x;
            sticks.push_back(make_pair(x, 0));
            stick_sum += x;
        }

        auto cmp = [](const PairType& lhs, const PairType& rhs){
            return lhs.first > rhs.first;
        };
        sort(sticks.begin(), sticks.end(), cmp);

        for(int ans = sticks[0].first; ans <= stick_sum; ++ans)
        {
            if(stick_sum % ans) continue;

            bool match = false;
            judge(ans, sticks, 0, 0, 0, match);
            if(match)
            {
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}
