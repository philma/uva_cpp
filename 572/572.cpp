#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<int> >& matrix, int row, int col, int count, int row_num, int col_num)
{
    int delta[8][2] = {{-1, 0},{1, 0},{0, 1},{0, -1},
                       {-1, -1},{-1, 1},{1, -1},{1, 1}};

    matrix[row][col] = count;
    for(int i = 0; i < 8; ++i)
    {
        int delta_row = row + delta[i][0];
        int delta_col = col + delta[i][1];
        if((delta_row >= 0 && delta_row < row_num)
           && (delta_col >= 0 && delta_col < col_num)
           && matrix[delta_row][delta_col] == -1)
        {
            dfs(matrix, delta_row, delta_col, count, row_num, col_num);
        }
    }
}

int main()
{
    int m = 0, n = 0;
    while(cin >> m >> n && m != 0)
    {
        vector<vector<int> > matrix;

        for(int i = 0; i < m; ++i)
        {
            string line;
            cin >> line;

            vector<int> tmp;
            for(int j = 0; j < line.size(); ++j)
                tmp.push_back(line[j] == '@' ? -1 : 0);
            matrix.push_back(tmp);
        }

        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] != -1)
                    continue;
                ++ans;
                dfs(matrix, i, j, ans, m, n);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
