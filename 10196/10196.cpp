#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const int ROW_SIZE = 8;
static const int COL_SIZE = 8;

enum SIDE
{
    WHITE = 0,
    BLACK
};

struct Direct
{
    Direct():x(0), y(0){}
    Direct(int xx, int yy):x(xx), y(yy){}

    int x;
    int y;
};

bool input_end(const vector<string>& matrix)
{
    for(size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = 0; j < matrix[i].size(); ++j)
        {
            if(matrix[i][j] != '.')
                return false;
        }
    }

    return true;
}

bool check_one_side(SIDE side, const vector<string>& matrix)
{
    char my_king = side == WHITE ? 'K' : 'k';
    char opp_king = side == WHITE ? 'k' : 'K';
    char soldier = side == WHITE ? 'p' : 'P';
    char horse = side == WHITE ? 'n' : 'N';
    char elephant = side == WHITE ? 'b' : 'B';
    char chariot = side == WHITE ? 'r' : 'R';
    char queen = side == WHITE ? 'q' : 'Q';

    bool check = false;
    for(size_t i = 0; i < matrix.size() && !check; ++i)
    {
        for(size_t j = 0; j < matrix[i].size() && !check; ++j)
        {
            if(matrix[i][j] == soldier
               ||matrix[i][j] == horse
               || matrix[i][j] == opp_king)
            {
                vector<Direct> directs;
                if((matrix[i][j] == soldier && side == WHITE)
                   || matrix[i][j] == opp_king)
                {
                    directs.push_back(Direct(1, -1));
                    directs.push_back(Direct(1, 1));
                }

                if((matrix[i][j] == soldier && side == BLACK)
                        || matrix[i][j] == opp_king)
                {
                    directs.push_back(Direct(-1, -1));
                    directs.push_back(Direct(-1, 1));
                }

                if(matrix[i][j] == opp_king)
                {
                    directs.push_back(Direct(-1, 0));
                    directs.push_back(Direct(1, 0));
                    directs.push_back(Direct(0, -1));
                    directs.push_back(Direct(0, 1));
                }

                if(matrix[i][j] == horse)
                {
                    directs.push_back(Direct(1, -2));
                    directs.push_back(Direct(1, 2));
                    directs.push_back(Direct(2, -1));
                    directs.push_back(Direct(2, 1));
                    directs.push_back(Direct(-1, -2));
                    directs.push_back(Direct(-1, 2));
                    directs.push_back(Direct(-2, -1));
                    directs.push_back(Direct(-2, 1));
                }

                for(size_t k = 0; k < directs.size(); ++k)
                {
                    int row_tmp = static_cast<int>(i) + directs[k].x;
                    int col_tmp = static_cast<int>(j) + directs[k].y;
                    if(!(row_tmp >= 0 && row_tmp < ROW_SIZE
                         && col_tmp >= 0 && col_tmp < COL_SIZE))
                        continue;
                    if(matrix[row_tmp][col_tmp] == my_king)
                    {
                        check = true;
                        break;
                    }
                }
            }
            else if(matrix[i][j] == elephant
                    || matrix[i][j] == chariot
                    || matrix[i][j] == queen)
            {
                vector<Direct> directs;
                if(matrix[i][j] == queen ||
                   matrix[i][j] == elephant)
                {
                    directs.push_back(Direct(-1, -1));
                    directs.push_back(Direct(-1, 1));
                    directs.push_back(Direct(1, -1));
                    directs.push_back(Direct(1, 1));
                }

                if(matrix[i][j] == queen
                   || matrix[i][j] == chariot)
                {
                    directs.push_back(Direct(0, -1));
                    directs.push_back(Direct(0, 1));
                    directs.push_back(Direct(-1, 0));
                    directs.push_back(Direct(1, 0));
                }


                for(size_t k = 0; k < directs.size() && !check; ++k)
                {
                    int row_tmp = static_cast<int>(i);
                    int col_tmp = static_cast<int>(j);
                    while(true)
                    {
                        row_tmp += directs[k].x;
                        col_tmp += directs[k].y;
                        if(!(row_tmp >= 0 && row_tmp < ROW_SIZE
                             && col_tmp >= 0 && col_tmp < COL_SIZE))
                                break;
                        if(matrix[row_tmp][col_tmp] != '.')
                        {
                            if(matrix[row_tmp][col_tmp] == my_king)
                                check = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    return check;
}

void check(const vector<string>& matrix)
{
    bool check_white = check_one_side(WHITE, matrix);
    bool check_black = check_one_side(BLACK, matrix);
    if(!check_white && !check_black)
        cout << "no king is in check." << endl;
    else if(!check_white && check_black)
        cout << "black king is in check." << endl;
    else if(check_white && !check_black)
        cout << "white king is in check." << endl;
}

int main()
{
    int case_num = 0;
    while(true)
    {
        vector<string> matrix;
        string line;
        for(int i = 0; i < ROW_SIZE; ++i)
        {
            getline(cin, line);
            matrix.push_back(line);
        }
        ++case_num;

        if(input_end(matrix))
            break;
        else
            getline(cin, line);

        cout << "Game #" << case_num << ": ";
        check(matrix);
    }

    return 0;
}
