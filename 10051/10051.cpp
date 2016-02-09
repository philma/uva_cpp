#include <iostream>
#include <vector>

using namespace std;

const unsigned char FACE_NUM = 6;
const string POSITIONS[FACE_NUM] = {"front", "back", "left", "right", "top", "bottom"};

struct CubeInfo
{
    unsigned char face_color[FACE_NUM];
};

struct NodeInfo
{
    unsigned short cube;
    unsigned char top_face;   
};

bool exist_edge(const NodeInfo& lhs, const NodeInfo& rhs
              , const vector<CubeInfo>& cubes)
{
    if(lhs.cube >= rhs.cube) return false;
    
    const CubeInfo& lhs_cube = cubes[lhs.cube];
    const CubeInfo& rhs_cube = cubes[rhs.cube];
    unsigned char lhs_bottom_color
        = (lhs.top_face & 1) ? lhs_cube.face_color[lhs.top_face - 1] : lhs_cube.face_color[lhs.top_face + 1];
    unsigned char rhs_top_color = rhs_cube.face_color[rhs.top_face];
    return lhs_bottom_color == rhs_top_color;
}

void create_graph(const vector<CubeInfo>& cubes
                , const vector<NodeInfo>& nodes
                , vector<vector<unsigned int> >& graph
                , vector<int>& indegree)
{
    for(unsigned int i = 0; i < nodes.size(); ++i)
    {
        for(unsigned int j = i + 1; j < nodes.size(); ++j)
        {
            if(exist_edge(nodes[i], nodes[j], cubes))
            {
                graph[i].push_back(j);
                ++indegree[j];
            }
        }
    }
}

void find_path(const vector<CubeInfo>& cubes
             , const vector<NodeInfo>& nodes
             , const vector<vector<unsigned int> >& graph
             , vector<int>& indegree
             , vector<vector<unsigned int> >& zero_indegree
             , vector<unsigned int>& path)
{
    unsigned int del_num = 0;
    unsigned int node_num = indegree.size();
    while(del_num < node_num)
    {
        vector<unsigned int>& to_del = zero_indegree[zero_indegree.size() - 1];
        vector<unsigned int> tmp;
        for(unsigned int i = 0; i < to_del.size(); ++i)
        {
            for(unsigned int j = 0; j < graph[to_del[i]].size(); ++j)
            {
                --(indegree[graph[to_del[i]][j]]);
                if(indegree[graph[to_del[i]][j]] == 0)
                    tmp.push_back(graph[to_del[i]][j]);
            }
            ++del_num;
        }
        if(!tmp.empty())
            zero_indegree.push_back(tmp);
    }

    path.resize(zero_indegree.size());
    unsigned int node_serial = zero_indegree[zero_indegree.size() - 1][0];
    path[path.size() - 1] = node_serial;
    for(int i = zero_indegree.size() - 2; i >= 0; --i)
    {
        for(unsigned int j = 0; j < zero_indegree[i].size(); ++j)
        {
            if(exist_edge(nodes[zero_indegree[i][j]], nodes[node_serial], cubes))
            {
                node_serial = zero_indegree[i][j];
                path[i] = node_serial;
                break;
            }
        }
    }
}

int main()
{
    int n = 0, case_num = 0;
    while(cin >> n && n)
    {
        ++case_num;
        if(case_num > 1)
            cout << endl;

        vector<CubeInfo> cubes;
        vector<NodeInfo> nodes;
        for(int i = 0; i < n; ++i)
        {
            CubeInfo cube_info;
            for(unsigned int j = 0; j < FACE_NUM; ++j)
            {
                int color = 0;
                cin >> color;
                cube_info.face_color[j] = color;

                NodeInfo node_info;
                node_info.cube = i;
                node_info.top_face = j;
                nodes.push_back(node_info);
            }
            cubes.push_back(cube_info);
        }

        vector<vector<unsigned int> > graph(nodes.size(), vector<unsigned int>());
        vector<int> indegree(nodes.size(), 0);
        create_graph(cubes, nodes, graph, indegree);
        
        vector<vector<unsigned int> > zero_indegree;
        vector<unsigned int> tmp;
        for(unsigned int i = 0; i < indegree.size(); ++i)
        {
            if(indegree[i] == 0)
                tmp.push_back(i);
        }
        zero_indegree.push_back(tmp);

        vector<unsigned int> path;
        find_path(cubes, nodes, graph, indegree, zero_indegree, path);

        cout << "Case #" << case_num << endl;
        cout << path.size() << endl;

        for(unsigned int i = 0; i < path.size(); ++i)
        {
            const NodeInfo& node_info = nodes[path[i]];
            cout << node_info.cube + 1 
                 << ' ' 
                 << POSITIONS[node_info.top_face]
                 << endl;
        }
    }
    return 0;
}
