#include <iostream>
#include <map>

using namespace std;

static const int MAX_EVENT = 20;

int process(int* student_rank, int n, map<int, int>& rank_info)
{
    int ans = 1;
    int dp[MAX_EVENT];

    dp[0] = 1;
    for(int i = 1; i < n; ++i)
    {
        int max = 1;
        for(int j = 0; j < i; ++j)
        {
            if(rank_info[student_rank[i]] > rank_info[student_rank[j]])
            {
                if(max < dp[j] + 1)
                    max = dp[j] + 1;
            }
        }
        dp[i] = max;
        if(ans < dp[i])
            ans = dp[i];
    }

    return ans;
}

int main()
{
    int n = 0;
    cin >> n;

    map<int, int> rank_info;
    for(int i = 1; i <= n; ++i)
    {
        int x = 0;
        cin >> x;
        rank_info.insert(make_pair(i, x));
    }

    int count = 0;
    int student_rank[MAX_EVENT];
    int x = 0;

    while(cin >> x)
    {
        ++count;
        student_rank[x - 1] = count;
        if(count == n)
        {
            cout << process(student_rank, n, rank_info) << endl;
            count = 0;
        }
    }

    return 0;
}
