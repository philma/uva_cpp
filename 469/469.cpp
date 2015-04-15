#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

void dfs(vector<vector<int> >& matrix, int row, int col, int count, int& area)
{
    int delta[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                       {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

    matrix[row][col] = count;
    ++area;
    for(int i = 0; i < 8; ++i)
    {
        int delta_row = row + delta[i][0];
        int delta_col = col + delta[i][1];
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        if((delta_row >= 0 && delta_row < row_num)
           && (delta_col >= 0 && delta_col < col_num)
            && matrix[delta_row][delta_col] == -1)
        {
            dfs(matrix, delta_row, delta_col, count, area);
        }
    }
}

void calc_lake_area(vector<vector<int> >& matrix, map<int, int>& lake_area)
{
    int count = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[i].size(); ++j)
        {
            if(matrix[i][j] != -1)
                continue;
            ++count;
            int area = 0;
            dfs(matrix, i, j, count, area);
            lake_area.insert(make_pair(count, area));
        }
    }
}

void answer_question(const vector<vector<int> >& questions, const vector<vector<int> >& matrix, const map<int, int>& lake_area)
{
    for(int i = 0; i < questions.size(); ++i)
    {
        int row = questions[i][0] - 1;
        int col = questions[i][1] - 1;
        map<int, int>::const_iterator it = lake_area.find(matrix[row][col]);
        cout << it->second << endl;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    getchar();
    int count = 0;
    while(n--)
    {
        ++count;
        string line;
        if(count == 1)
            getline(cin, line);

        vector<vector<int> > matrix;
        vector<vector<int> > questions;
        while(getline(cin, line) && line != "")
        {
            if(line[0] == 'L' || line[0] == 'W')
            {
                vector<int> tmp;
                for(int i = 0; i < line.size(); ++i)
                    tmp.push_back(line[i] == 'L' ? 0 : -1);
                matrix.push_back(tmp);
            }
            else
            {
                int number = 0;
                vector<int> tmp;
                for(int i = 0; i < line.size() && tmp.size() < 2; ++i)
                {
                    if(line[i] >= '0' && line[i] <= '9')
                    {
                        number = 10 * number + (line[i] - '0');
                        if(i == line.size() - 1)
                            tmp.push_back(number);
                    }
                    else if(number != 0)
                    {
                        tmp.push_back(number);
                        number = 0;
                    }
                }
                questions.push_back(tmp);
            }
        }

        map<int, int> lake_area;
        calc_lake_area(matrix, lake_area);
        answer_question(questions, matrix, lake_area);

        if(n != 0) cout << endl;
    }

    return 0;
}
