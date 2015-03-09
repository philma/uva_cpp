#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

static const int MAX_ROW = 50;
static const int MAX_COL = 50;

static const int EAST = 3;
static const int WEST = 2;
static const int SOUTH = 1;
static const int NORTH = 0;

class Direction
{
public:
    Direction():direction(0){}

    bool has_direction(int direct) const
    {
        return (direction & (1 << direct));
    }

    void set_direction(int direct)
    {
        direction |= (1 << direct);
    }

private:
    unsigned char direction;
};

class Matrix
{
public:
    Matrix():row(0), col(0)
    {
        memset(matrix, 0, sizeof(matrix));
    }

    bool is_obstacle(int x, int y) const
    {
        assert(x >= 0 && x <= row);
        assert(y >= 0 && y <= col);

        int ans = 0;
        if(x > 0 && y > 0)
            ans |= matrix[x - 1][y - 1];
        if(x > 0 && y < col)
            ans |= matrix[x - 1][y];
        if(x < row && y > 0)
            ans |= matrix[x][y - 1];
        if(x < row && y < col)
            ans |= matrix[x][y];

        return ans;
    }

public:
    int row;
    int col;
    int matrix[MAX_ROW][MAX_COL];
};

class Step
{
public:
    Step():x(0), y(0), direct(SOUTH), time(0){}
    Step(int xx, int yy, int d):x(xx), y(yy), direct(d), time(0){}

    void turn_left_commd(Step& next_step)
    {
        next_step.x = x;
        next_step.y = y;
        next_step.time = time + 1;
        if(direct == EAST)
            next_step.direct = NORTH;
        else if(direct == WEST)
            next_step.direct = SOUTH;
        else if(direct == SOUTH)
            next_step.direct = EAST;
        else
            next_step.direct = WEST;
    }

    void turn_right_commd(Step& next_step)
    {
        next_step.x = x;
        next_step.y = y;
        next_step.time = time + 1;
        if(direct == EAST)
            next_step.direct = SOUTH;
        else if(direct == WEST)
            next_step.direct = NORTH;
        else if(direct == SOUTH)
            next_step.direct = WEST;
        else
            next_step.direct = EAST;
    }

    bool go_commd(const Matrix& matrix, Step& next_step, int n)
    {
        assert(n >= 1 && n <= 3);
        next_step.direct = direct;
        next_step.time = time + 1;
        if(direct == EAST)
        {
            if(y + n >= matrix.col)
                return false;
            for(int i = 1; i <= n; ++i)
            {
                if(matrix.is_obstacle(x, y + i))
                    return false;
            }
            next_step.x = x;
            next_step.y = y + n;
        }
        else if(direct == WEST)
        {
            if(y - n <= 0)
                return false;
            for(int i = 1; i <= n; ++i)
            {
                if(matrix.is_obstacle(x, y - i))
                    return false;
            }
            next_step.x = x;
            next_step.y = y - n;
        }
        else if(direct == SOUTH)
        {
            if(x + n >= matrix.row)
                return false;
            for(int i = 1; i <= n; ++i)
            {
                if(matrix.is_obstacle(x + i, y))
                    return false;
            }
            next_step.x = x + n;
            next_step.y = y;
        }
        else
        {
            if(x - n <= 0)
                return false;
            for(int i = 1; i <= n; ++i)
            {
                if(matrix.is_obstacle(x - i, y))
                    return false;
            }
            next_step.x = x - n;
            next_step.y = y;
        }

        return true;
    }

public:
    int x;
    int y;
    int direct;
    int time;
};

int main()
{
    Matrix matrix;
    vector<Step> steps;
    steps.reserve(4*(MAX_ROW + 1)*(MAX_COL + 1));

    while(cin >> matrix.row >> matrix.col)
    {
        if(matrix.row == 0 && matrix.col == 0)
            break;

        for(int i = 0; i < matrix.row; ++i)
        {
            for(int j = 0; j < matrix.col; ++j)
                cin >> matrix.matrix[i][j];
        }

        int b1 = 0, b2 = 0;
        int e1 = 0, e2 = 0;
        string tmp;
        cin >> b1 >> b2 >> e1 >> e2 >> tmp;

        int direct = 0;
        if(tmp == "north")
            direct = NORTH;
        else if(tmp == "west")
            direct = WEST;
        else if(tmp == "south")
            direct = SOUTH;
        else
            direct = EAST;

        Step start(b1, b2, direct);
        vector<Direction> directions((matrix.row + 1)*(matrix.col + 1));

        steps.clear();
        steps.push_back(start);
        directions[start.x * (matrix.col + 1) + start.y].set_direction(start.direct);

        bool arrive = false;
        for(int i = 0; i < steps.size(); ++i)
        {
            if(steps[i].x == e1 && steps[i].y == e2)
            {
                cout << steps[i].time << endl;
                arrive = true;
                break;
            }

            Step next_step;

            steps[i].turn_left_commd(next_step);
            if(!directions[next_step.x * (matrix.col + 1) + next_step.y].has_direction(next_step.direct))
            {
                steps.push_back(next_step);
                directions[next_step.x * (matrix.col + 1) + next_step.y].set_direction(next_step.direct);
            }

            steps[i].turn_right_commd(next_step);
            if(!directions[next_step.x * (matrix.col + 1) + next_step.y].has_direction(next_step.direct))
            {
                steps.push_back(next_step);
                directions[next_step.x * (matrix.col + 1) + next_step.y].set_direction(next_step.direct);
            }

            for(int j = 1; j <= 3; ++j)
            {
                if(!steps[i].go_commd(matrix, next_step, j))
                    break;
                if(!directions[next_step.x * (matrix.col + 1) + next_step.y].has_direction(next_step.direct))
                {
                    steps.push_back(next_step);
                    directions[next_step.x * (matrix.col + 1) + next_step.y].set_direction(next_step.direct);
                }
            }
        }

        if(!arrive)
            cout << -1 << endl;
    }

    return 0;
}
