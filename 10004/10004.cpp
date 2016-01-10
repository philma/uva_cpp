#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int> >& graph, vector<char>& nodes_color
        , int node, char color
        , bool& bicolorable)
{
    nodes_color[node] = color;

    char next_color = ~color;
    for(unsigned int i = 0; i < graph[node].size() && bicolorable; ++i)
    {
        int next_node = graph[node][i];
        if(nodes_color[next_node] == '*')
            dfs(graph, nodes_color, next_node, next_color, bicolorable);
        else if(nodes_color[next_node] == color)
            bicolorable = false;
    }
}

int main()
{
    int node_num = 0;
    while(cin >> node_num && node_num)
    {
        vector<vector<int> > graph(node_num, vector<int>());
        int edge_num = 0;
        cin >> edge_num;
        for(int i = 0; i < edge_num; ++i)
        {
            int node1 = 0, node2 = 0;
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        vector<char> nodes_color(node_num, '*');
        bool bicolorable = true;
        int node = 0;
        char color = 0;
        dfs(graph, nodes_color, node, color, bicolorable);

        if(!bicolorable) cout << "NOT ";
        cout << "BICOLORABLE." << endl;
    }
    
    return 0;
}
