#include <iostream>
#include <vector>
#include <string>

using namespace std;

const static int SQUARE_SIZE = 5;

void find_blank(const vector<string>& puzzle, int& blank_row, int& blank_col)
{
    for(int i = 0; i < puzzle.size(); ++i)
    {
        for(int j = 0; j < puzzle[i].size(); ++j)
        {
            if(puzzle[i][j] == ' ')
            {
                blank_row = i;
                blank_col = j;
                return ;
            }
        }
    }
}

bool check_position(int row, int col)
{
    if((row >=0 && row < SQUARE_SIZE)
       && (col >=0 && col < SQUARE_SIZE))
        return true;
    return false;
}

bool move_one_step(vector<string>& puzzle, char c, int& blank_row, int& blank_col)
{
    int row_delta = 0, col_delta = 0;
    if(c == 'A')
        row_delta = -1;
    else if(c == 'B')
        row_delta  = 1;
    else if(c == 'R')
        col_delta = 1;
    else
        col_delta = -1;

    if(!check_position(blank_row + row_delta, blank_col + col_delta))
        return false;

    puzzle[blank_row][blank_col] = puzzle[blank_row + row_delta][blank_col + col_delta];
    puzzle[blank_row + row_delta][blank_col + col_delta] = ' ';
    blank_row += row_delta;
    blank_col += col_delta;

    return true;
}

void output_puzzle(const vector<string>& puzzle)
{
    for(int i = 0; i < puzzle.size(); ++i)
    {
        for(int j = 0; j < puzzle[i].size(); ++j)
        {
            cout << puzzle[i][j];
            if(j == puzzle[i].size() - 1)
                cout << endl;
            else
                cout << ' ';
        }
    }
}

int main()
{
    int count = 0;
    string line;
    while(getline(cin, line))
    {
        if(line == "Z")
            break;
        ++count;
        if(count > 1) cout << endl;

        vector<string> puzzle;
        puzzle.push_back(line);

        for(int i = 0; i < SQUARE_SIZE - 1; ++i)
        {
            getline(cin, line);
            puzzle.push_back(line);
        }

        bool illegal = false;
        while(getline(cin, line))
        {
            int blank_row = 0, blank_col = 0;
            find_blank(puzzle, blank_row, blank_col);
            for(int i = 0; i < line.size(); ++i)
            {
                if(line[i] == '0') continue;
                if(!move_one_step(puzzle, line[i], blank_row, blank_col))
                {
                    illegal = true;
                    break;
                }
            }

            if(line[line.size() - 1] == '0')
                break;
        }

        cout << "Puzzle #" << count << ":" << endl;
        if(!illegal)
            output_puzzle(puzzle);
        else
            cout << "This puzzle has no final configuration." << endl;

    }

    return 0;
}
