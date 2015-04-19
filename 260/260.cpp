/*
 * Created on: 2015-04-19
 *     Author: philma
 */

#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string>& matrix, string& flag, int row, int col, char c)
{
    int delta[6][2] = {{-1, -1},{-1, 0},{0, -1},
                       {0, 1},{1, 0},{1, 1}};

    matrix[row][col] = '*';
    if(c == 'w')
        flag[col] = '1';
    else
        flag[row] = '1';

    int n = matrix.size();
    for(int i = 0; i < 6; ++i)
    {
        int delta_row = row + delta[i][0];
        int delta_col = col + delta[i][1];

        if((delta_row >= 0 && delta_row < n)
           && (delta_col >= 0 && delta_col < n)
           && matrix[delta_row][delta_col] == c)
        {
            dfs(matrix, flag, delta_row, delta_col, c);
        }
    }
}

bool judge_flag(const string& flag)
{
    int sum = 1;
    for(int i = 0; i < flag.size(); ++i)
        sum &= flag[i] == '0' ? 0 : 1;
    return sum;
}

int main()
{
    int n = 0;
    int count = 0;
    while(cin >> n && n)
    {
        ++count;
        vector<string> matrix;
        string line;
        for(int i = 0; i < n; ++i)
        {
            cin >> line;
            matrix.push_back(line);
        }

        //只遍历第一行和第一列，对b和w的点dfs
        for(int i = 0; i < n; ++i)
        {
            if(matrix[0][i] == 'b')
            {
                string flag(n, '0');
                dfs(matrix, flag, 0, i, 'b');
                if(judge_flag(flag))
                {
                    cout << count << " B" << endl;
                    break;
                }
            }

            if(matrix[i][0] == 'w')
            {
                string flag(n, '0');
                dfs(matrix, flag, i, 0, 'w');
                if(judge_flag(flag))
                {
                    cout << count << " W" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
