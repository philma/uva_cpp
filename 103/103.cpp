#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

static const int MAX_K = 30;

bool vec_cmp(const vector<int>& lhs, const vector<int>& rhs)
{
    if(lhs.size() != rhs.size())
        return false;
    int len = lhs.size();
    for(int i = 0; i < len; ++i)
    {
        if(lhs[i] >= rhs[i])
            return false;
    }

    return true;
}

void read_input(vector<vector<int> >& data, int k, int n)
{
    data.clear();
    for(int i = 0; i < k; ++i)
    {
        data.push_back(vector<int>());
        vector<vector<int> >::iterator it = data.end() - 1;
        for(int j = 0; j < n; ++j)
        {
            int tmp;
            cin >> tmp;
            it->push_back(tmp);
        }
        sort(it->begin(), it->end());
    }
}

void init_graph(map<int, vector<int> >& graph, const vector<vector<int> >& data, int k)
{
    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            if(i == j) continue;
            if(vec_cmp(data[i], data[j]))
            {
                if(graph.find(i) == graph.end())
                {
                    vector<int> tmp;
                    tmp.push_back(j);
                    graph.insert(make_pair(i, tmp));
                }
                else
                    graph[i].push_back(j);
            }
        }
    }
}

void dfs(map<int, vector<int> >& graph, vector<int>& tmp, vector<int>& ans)
{
    if(tmp.empty())
    {
        map<int, vector<int> >::const_iterator it = graph.begin();
        for(;it != graph.end(); ++it)
        {
            tmp.push_back(it->first);
            dfs(graph, tmp, ans);
            tmp.erase(tmp.end() - 1);
        }
    }
    else
    {
        int len = graph[*(tmp.rbegin())].size();
        for(int i = 0; i < len; ++i)
        {
            int next = graph[*(tmp.rbegin())][i];
            tmp.push_back(next);
            if(graph.find(next) == graph.end())
            {
                if(tmp.size() > ans.size())
                    ans = tmp;
            }
            else
                dfs(graph, tmp, ans);
            tmp.erase(tmp.end() - 1);
        }
    }
}

void output_ans(const vector<int>& ans)
{
    if(ans.empty())
    {
        cout << 1 << endl << 1 << endl;
        return ;
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
    {
        if(i != 0)
            cout << " ";
        cout << ans[i]+ 1;
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > data;
    int k = 0, n = 0;

    while(cin >> k >> n)
    {
        read_input(data, k, n);

        if(k == 1)
        {
            cout << k << endl;
            cout << k << endl;
            continue;
        }

        map<int, vector<int> > graph;
        init_graph(graph, data, k);

        vector<int> tmp;
        vector<int> ans;

        tmp.reserve(MAX_K);
        ans.reserve(MAX_K);
        dfs(graph, tmp, ans);

        output_ans(ans);
    }

    return 0;
}
