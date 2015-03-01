#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAX_ROW = 10;
static const int MAX_COL = 100;

struct Node
{
    int weight;
    int sum;
    vector<int> path; 
};

struct VecCmp
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs)
    {
        for(unsigned int i = 0; i < lhs.size() &&  i < rhs.size(); ++i)
        {
            if(lhs[i] == rhs[i])
                continue;
            return lhs[i] < rhs[i];
        }

        return lhs.size() < rhs.size();
    }
};

void suitable_node(const vector<Node>& nodes, Node& suit_one)
{
    int pos = 0;
    VecCmp cmp_obj;

    for(unsigned int i = 1; i < nodes.size(); ++i)
    {
        if(nodes[pos].sum > nodes[i].sum
                || (nodes[pos].sum == nodes[i].sum && cmp_obj(nodes[i].path, nodes[pos].path)))
            pos = i;
    }

    suit_one = nodes[pos];
}

void vector_push(int prev_row, int col, vector<Node>& nodes, Node dp[][MAX_COL])
{
    Node tmp;

    tmp.path = dp[prev_row][col - 1].path;
    tmp.sum = dp[prev_row][col - 1].sum;
    nodes.push_back(tmp);
}

int main()
{
    Node dp[MAX_ROW][MAX_COL];
    int row = 0, col = 0;

    while(cin >> row >> col)
    {
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                cin >> dp[i][j].weight;
                if(j == 0)
                {
                    dp[i][j].sum = dp[i][j].weight;
                    dp[i][j].path.clear();
                    dp[i][j].path.push_back(i);
                }
            }
        }

        for(int j = 1; j < col; ++j)
        {
            for(int i = 0; i < row; ++i)
            {
                vector<Node> nodes;
                Node suit_one;
                
                if(row <= 3)
                {
                    for(int k = 0; k < row; ++k)
                        vector_push(k, j, nodes, dp);
                }
                else
                {
                    if(i == 0)
                    {
                        vector_push(0, j, nodes, dp);
                        vector_push(1, j, nodes, dp);
                        vector_push(row - 1, j, nodes, dp);
                    }
                    else if(i == row - 1)
                    {
                        vector_push(0, j, nodes, dp);
                        vector_push(i - 1, j, nodes, dp);
                        vector_push(i, j, nodes, dp);
                    }
                    else
                    {
                        vector_push(i - 1, j, nodes, dp);
                        vector_push(i, j, nodes, dp);
                        vector_push(i + 1, j, nodes, dp);
                    }
                }

                suitable_node(nodes, suit_one);
                dp[i][j].sum = suit_one.sum + dp[i][j].weight;
                dp[i][j].path = suit_one.path;
                dp[i][j].path.push_back(i);
            }
        }

        int pos = 0;
        VecCmp cmp_obj;

        for(int i = 1; i < row; ++i)
        {
            if(dp[pos][col - 1].sum > dp[i][col - 1].sum
                    || (dp[pos][col - 1].sum == dp[i][col - 1].sum && cmp_obj(dp[i][col - 1].path, dp[pos][col - 1].path)))
            {
                pos = i;
            }
        }

        for(unsigned int i = 0; i < dp[pos][col - 1].path.size(); ++i)
        {
            if(i != 0)
                cout << " ";
            cout << dp[pos][col - 1].path[i] + 1;
        }
        cout << endl << dp[pos][col - 1].sum << endl;
    }

    return 0;
}
