/*
 * Created on: 2015-05-11
 *     Author: philma
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const static int MAX_SIZE = 75;

void init(vector<string>& matrix)
{
    int row = 2 * MAX_SIZE - 1;
    for(int i = 0; i < row; ++i)
    {
        int col = 0;
        if(i & 1)
            col = MAX_SIZE;
        else
            col = MAX_SIZE - 1;

        string tmp(col, '0');
        matrix.push_back(tmp);
    }
}

void print_matrix(const vector<string>& matrix)
{
    for(unsigned int i = 0; i < matrix.size(); ++i)
        cout << matrix[i] << endl;
}

void dfs(const vector<string>& maze, vector<string>& matrix, int row, int col, int& flag, int& length)
{
    matrix[row][col] = '1';
    ++length;

    int odd_delta[4][2] = {{-1, -1}, {-1, 0}, {1, -1}, {1, 0}};
    int even_delta[4][2] = {{-1, 0}, {-1, 1}, {1, 0}, {1, 1}};
    char slashes[4] = {'\/', '\\', '\\', '\/'};

    for(int i = 0; i < 4; ++i)
    {
        int next_row = row;
        int next_col = col;

        if(row & 1)
        {
            next_row += odd_delta[i][0];
            next_col += odd_delta[i][1];
        }
        else
        {
            next_row += even_delta[i][0];
            next_col += even_delta[i][1];
        }

        char slash = '*';
        if(row & 1)
        {
            if(i < 2)
            {
                if((row - 1) / 2 < maze.size() && col < maze[(row - 1) / 2].size())
                    slash = maze[(row - 1) / 2][col];
            }
            else
            {
                if((row + 1) / 2 < maze.size() && col < maze[(row + 1) / 2].size())
                    slash = maze[(row + 1) / 2][col];
            }
        }
        else
        {
            if(i & 1)
            {
                if(row / 2 < maze.size() && col + 1 < maze[row / 2].size())
                    slash = maze[row / 2][col + 1];
            }
            else
            {
                if(row / 2 < maze.size() && col < maze[row / 2].size())
                    slash = maze[row / 2][col];
            }
        }

        if(slash == slashes[i])
            continue;

        if(!(next_row >= 0 && next_row < matrix.size()
             && next_col >= 0 && next_col < matrix[next_row].size()))
        {
            flag = 1;
            continue;
        }

        if(matrix[next_row][next_col] != '0')
            continue;

        dfs(maze, matrix, next_row, next_col, flag, length);
    }
}

void process(const vector<string>& maze, vector<string>& matrix, int case_count)
{
    int count = 0, max_len = -1;
    for(unsigned int i = 0; i < matrix.size(); ++i)
    {
        for(unsigned int j = 0; j < matrix[i].size(); ++j)
        {
            if(matrix[i][j] != '0') continue;

            int flag = 0, length = 0;
            dfs(maze, matrix, i, j, flag, length);
            if(flag == 0)
            {
                ++count;
                if(length > max_len)
                    max_len = length;
            }
        }
    }

    cout << "Maze #" << case_count << ":" << endl;
    if(count == 0)
        cout << "There are no cycles." << endl;
    else
        cout << count << " Cycles; the longest has length " << max_len << "." << endl;
    cout << endl;
}

int main()
{
    int width = 0, height = 0;
    int case_count = 0;
    while(cin >> width >> height
            && width && height)
    {
        ++case_count;
        vector<string> maze;
        for(int i = 0; i < height; ++i)
        {
            string tmp;
            cin >> tmp;
            maze.push_back(tmp);
        }

        vector<string> matrix;
        init(matrix);
        process(maze, matrix, case_count);
    }

    return 0;
}
