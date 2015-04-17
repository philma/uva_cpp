#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string>& matrix, int row, int col)
{
    int delta[8][2] = {{-1,0},{1,0},{0,-1},{0,1},
                       {-1,-1},{-1,1},{1,-1},{1,1}};

    int row_num = matrix.size();
    int col_num = matrix.size();

    matrix[row][col] = '0';
    for(int i = 0; i < 8; ++i)
    {
        int delta_row = row + delta[i][0];
        int delta_col = col + delta[i][1];
        if((delta_row >= 0 && delta_row < row_num)
           && (delta_col >= 0 && delta_col < col_num)
           && matrix[delta_row][delta_col] == '1')
        {
            dfs(matrix, delta_row, delta_col);
        }
    }
}

int main()
{
    int n = 0, count = 0;
    while(cin >> n)
    {
        ++count;
        vector<string> matrix;
        for(int i = 0; i < n; ++i)
        {
            string line;
            cin >> line;
            matrix.push_back(line);
        }

        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] != '1') continue;
                ++ans;
                dfs(matrix, i, j);
            }
        }

        cout << "Image number " << count << " contains " << ans << " war eagles." << endl;
    }

    return 0;
}
