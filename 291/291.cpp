#include <iostream>
#include <vector>

using namespace std;

static const int VERTEX_NUM = 5;
static const int EDGE_NUM = 8;

void init_graph(vector<vector<int> >& graph)
{
    int edges[EDGE_NUM][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2},
                              {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    for(int i = 0; i < EDGE_NUM; ++i)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
}

void dfs(vector<vector<int> >& graph, vector<int>& path)
{
    int prev = 0;
    if(path.empty())
    {
        prev = 0;
        path.push_back(prev);
    }
    else
        prev = *(path.rbegin());

    bool exist_path = false;
    for(int i = 0; i < VERTEX_NUM; ++i)
    {
        if(graph[prev][i])
        {
            exist_path = true;

            path.push_back(i);
            graph[prev][i] = 0;
            graph[i][prev] = 0;
            dfs(graph, path);
            path.erase(path.end() - 1);
            graph[prev][i] = 1;
            graph[i][prev] = 1;
        }
    }

    if(!exist_path && path.size() == EDGE_NUM + 1)
    {
        for(int i = 0; i < path.size(); ++i)
            cout << path[i] + 1;
        cout << endl;
    }
}

int main()
{
    vector<int> tmp(VERTEX_NUM, 0);
    vector<vector<int> > graph(VERTEX_NUM, tmp);

    init_graph(graph);

    vector<int> path;
    dfs(graph, path);

    return 0;
}
