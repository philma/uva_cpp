#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Edge
{
    char direc;
    int a;
    int b;
};

struct Case
{
    int n;
    vector<Edge> edges;
};

void case_input(vector<Case>& cases)
{
    int m = 0;
    Case single_case;
    while(cin >> single_case.n >> m)
    {
        single_case.edges.clear();
        for(int i = 0; i < m; ++i)
        {
            Edge edge;
            cin >> edge.direc >> edge.a >> edge.b;
            single_case.edges.push_back(edge);
        }
        cases.push_back(single_case);
    }
}

int calc_serial(int n, int row, int col)
{
    return row * n + col;
}

void init_graph(vector<vector<int> >& graph, const Case& s_case)
{
    for(int i = 0; i < s_case.edges.size(); ++i)
    {
        const Edge& edge = s_case.edges[i];
        int x = 0, y = 0;
        if(edge.direc == 'H')
        {
            x = calc_serial(s_case.n, edge.a - 1, edge.b - 1);
            y = calc_serial(s_case.n, edge.a - 1, edge.b);
        }
        else
        {
            x = calc_serial(s_case.n, edge.b - 1, edge.a - 1);
            y = calc_serial(s_case.n, edge.b, edge.a - 1);
        }
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
}

bool check_square(const vector<vector<int> >& graph, int row, int col, int len, int n)
{
    for(int i = 1; i <= len; ++i)
    {
        int x = calc_serial(n, row, col + i - 1);
        int y = calc_serial(n, row, col + i);
        if(!graph[x][y]) return false;
        
        x = calc_serial(n, row + len, col + i -1);
        y = calc_serial(n, row + len, col + i);
        if(!graph[x][y]) return false;
        
        x = calc_serial(n, row + i -1 , col);
        y = calc_serial(n, row + i, col);
        if(!graph[x][y]) return false;

        x = calc_serial(n, row + i - 1, col + len);
        y = calc_serial(n, row + i, col + len);
        if(!graph[x][y]) return false;
    }

    return true;
}

void get_ans(map<int, int>& ans, const vector<vector<int> >& graph, const Case& s_case)
{
    for(int i = 0; i < s_case.n; ++i)
    {
        for(int j = 0; j < s_case.n; ++j)
        {
            for(int k = 1; k < s_case.n; ++k)
            {
                if(i + k >= s_case.n || j + k >= s_case.n)
                    break;
                if(check_square(graph, i, j, k, s_case.n))
                {
                    if(ans.find(k) == ans.end())
                        ans.insert(make_pair(k, 1));
                    else
                        ++ans[k];
                } 
            }
        }
    }
}

void output_tail()
{
    cout << endl;
    cout << "**********************************" << endl;
    cout << endl;
}

void output_ans(const map<int, int>& ans, int problem_serial, bool tail)
{
    cout << "Problem #" << problem_serial << endl;
    for(map<int, int>::const_iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << endl << it->second << " square (s) of size " << it->first;
    }

    if(ans.empty())
    {
        cout << endl << "No completed squares can be found.";
    }

    cout << endl;
    
    if(tail)
        output_tail();
}

void process_cases(const vector<Case>& cases)
{
    for(int i = 0; i < cases.size(); ++i)
    {
        const Case& s_case = cases[i];
        
        vector<int> tmp(s_case.n * s_case.n, 0);
        vector<vector<int> > graph(s_case.n * s_case.n, tmp);
        init_graph(graph, s_case);

        map<int, int> ans;
        get_ans(ans, graph, s_case);
        output_ans(ans, i + 1, (i < cases.size() - 1)); 
    }
}

int main()
{
    vector<Case> cases;
    case_input(cases);
    process_cases(cases);

    return 0; 
}
