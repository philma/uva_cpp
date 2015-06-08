#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef void(*Behaviour)(vector<string>&, const string&);

int str_2_num(const string& str)
{
    int num = 0;
    for(unsigned int i = 0; i < str.size(); ++i)
        num = 10 * num + str[i] - '0';
    return num;
}

void do_cmd_I(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    int col = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    int row = str_2_num(cmd.substr(space2 + 1, cmd.size() - space2 - 1));

    matrix.clear();
    string tmp(col, 'O');
    for(int i = 0; i < row; ++i)
        matrix.push_back(tmp);
}

void do_cmd_C(vector<string>& matrix, const string& cmd)
{
    for(unsigned int i = 0; i < matrix.size(); ++i)
    {
        for(unsigned int j = 0; j < matrix[i].size(); ++j)
            matrix[i][j] = 'O';
    }
}

void do_cmd_L(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    size_t space3 = cmd.find(' ', space2 + 1);
    int row = str_2_num(cmd.substr(space2 + 1, space3 - space2 - 1));
    int col = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    matrix[row - 1][col - 1] = cmd[cmd.size() - 1];
}

void do_cmd_V(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    size_t space3 = cmd.find(' ', space2 + 1);
    size_t space4 = cmd.find(' ', space3 + 1);
    int col = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    int row1 = str_2_num(cmd.substr(space2 + 1, space3 - space2 - 1));
    int row2 = str_2_num(cmd.substr(space3 + 1, space4 - space3 - 1));
    if(row1 > row2)
        swap(row1, row2);

    for(int i = row1 - 1; i <= row2 - 1; ++i)
        matrix[i][col - 1] = cmd[cmd.size() - 1];
}

void do_cmd_H(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    size_t space3 = cmd.find(' ', space2 + 1);
    size_t space4 = cmd.find(' ', space3 + 1);
    int row = str_2_num(cmd.substr(space3 + 1, space4 - space3 - 1));
    int col1 = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    int col2 = str_2_num(cmd.substr(space2 + 1, space3 - space2 - 1));
    if(col1 > col2)
        swap(col1, col2);

    for(int i = col1 - 1; i <= col2 - 1; ++i)
        matrix[row - 1][i] = cmd[cmd.size() - 1];
}

void do_cmd_K(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    size_t space3 = cmd.find(' ', space2 + 1);
    size_t space4 = cmd.find(' ', space3 + 1);
    size_t space5 = cmd.find(' ', space4 + 1);
    int row1 = str_2_num(cmd.substr(space2 + 1, space3 - space2 - 1));
    int row2 = str_2_num(cmd.substr(space4 + 1, space5 - space4 - 1));
    int col1 = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    int col2 = str_2_num(cmd.substr(space3 + 1, space4 - space3 - 1));

    for(int i = row1 - 1; i <= row2 - 1; ++i)
        for(int j = col1 - 1; j <= col2 - 1; ++j)
            matrix[i][j] = cmd[cmd.size() - 1];
}

void dfs(int row, int col, char color, char to_color, set<int>& pos_set, vector<string>& matrix)
{
    int delta[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    matrix[row][col] = to_color;
    pos_set.insert(row * matrix[0].size() + col);

    for(int i = 0; i < 4; ++i)
    {
        int next_row = row + delta[i][0];
        int next_col = col + delta[i][1];

        if(!(next_row >= 0 && next_row < matrix.size()
             && next_col >= 0 && next_col < matrix[0].size()
             && matrix[next_row][next_col] == color
             && pos_set.find(next_row * matrix[0].size() + next_col) == pos_set.end()))
                continue;
        dfs(next_row, next_col, color, to_color, pos_set, matrix);
    }
}

void do_cmd_F(vector<string>& matrix, const string& cmd)
{
    size_t space1 = cmd.find(' ');
    size_t space2 = cmd.find(' ', space1 + 1);
    size_t space3 = cmd.find(' ', space2 + 1);
    int row = str_2_num(cmd.substr(space2 + 1, space3 - space2 - 1));
    int col = str_2_num(cmd.substr(space1 + 1, space2 - space1 - 1));
    set<int> pos_set;
    dfs(row - 1, col - 1, matrix[row - 1][col - 1], cmd[cmd.size() - 1], pos_set, matrix);
}

void do_cmd_S(vector<string>& matrix, const string& cmd)
{
    string name = cmd.substr(2, cmd.size() - 2);
    cout << name << endl;
    for(unsigned int i = 0; i < matrix.size(); ++i)
        cout << matrix[i] << endl;
}

bool do_cmd(vector<string>& matrix, const string& cmd, const map<char, Behaviour>& behaviours)
{
    if(cmd[0] == 'X')
        return false;

    map<char, Behaviour>::const_iterator it = behaviours.find(cmd[0]);
    if(it != behaviours.end())
        it->second(matrix, cmd);

    return true;
}

void do_regist(map<char, Behaviour>& behaviours)
{
    behaviours.insert(make_pair('I', do_cmd_I));
    behaviours.insert(make_pair('C', do_cmd_C));
    behaviours.insert(make_pair('L', do_cmd_L));
    behaviours.insert(make_pair('V', do_cmd_V));
    behaviours.insert(make_pair('H', do_cmd_H));
    behaviours.insert(make_pair('K', do_cmd_K));
    behaviours.insert(make_pair('F', do_cmd_F));
    behaviours.insert(make_pair('S', do_cmd_S));
}

int main()
{
    map<char, Behaviour> behaviours;
    do_regist(behaviours);

    string cmd;
    vector<string> matrix;
    while(getline(cin, cmd))
    {
        if(!do_cmd(matrix, cmd, behaviours))
            break;
    }

    return 0;
}
