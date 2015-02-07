#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int value;
    char blank;
};

void do_work(char c, int& state, int& sum, stack<Node>& nodes, int& lbracket, int& tmp, int& rat, int& flag)
{
    switch(state)
    {
        case 0:
        {
            if(c == '-')
            {
                rat = -1;
                state = 1;
            }
            else
            {
                sum = 10 * sum + (c - '0');
                state = 1;
            }
            break;
        }
        case 1:
        {
            if(c != '(')
                sum = 10 * sum + (c - '0');
            else
            {
                state = 2;
                sum *= rat;
                rat = 1;
                tmp = 0;
                lbracket = 1;
            }
            break;
        }
        case 2:
        {
            if(c == ')')
            {
                --lbracket;
                state = 0;
                sum = 0;
                tmp = 0;
                rat = 1;
                flag = 0;
                cout << "no" << endl;
            }
            else if(c == '-')
            {
                rat = -1;
                state = 3;
            }
            else
            {
                state = 3;
                tmp = 10 * tmp + (c - '0');
            }
            break;
        }
        case 3:
        {
            if(c == '(')
            {
                tmp *= rat;
                rat = 1;
                Node node = {tmp, 0};
                nodes.push(node);
                tmp = 0;
                state = 4;
                sum -= node.value;
                ++lbracket;
            }
            else
                tmp = 10 * tmp + (c - '0');
            break;
        }
        case 4:
        {
            if(c == ')')
            {
                --lbracket;
                nodes.top().blank++;
                state = 5;
            }
            else if(c == '-')
            {
                state = 3;
                rat = -1;
            }
            else
            {
                state = 3;
                tmp = 10 * tmp + (c - '0');
            }
            break;
        }
        case 5:
        {
            if(c == '(')
            {
                ++lbracket;
                state = 4;
            }
            else
            {
                --lbracket;
                if(nodes.top().blank == 2 && sum == 0)
                    flag = 1;
                sum += nodes.top().value;
                nodes.pop();
                if(nodes.empty())
                {
                    if(flag == 1)
                        cout << "yes" << endl;
                    else
                        cout << "no" << endl;
                    state = 0;
                    sum = 0;
                    lbracket = 0;
                    tmp = 0;
                    rat = 1;
                    flag = 0;
                }
            }
            break;
        }
        default:
            break;
    }
}

int main()
{
    char c;
    stack<Node> nodes;
    int sum = 0, tmp = 0, flag = 0;
    int lbracket = 0, state = 0, rat = 1;

    while(cin >> c)
    {
        if(!(c >= '0' && c <= '9') && c != '(' && c != ')' && c != '-' )
            continue;
        do_work(c, state, sum, nodes, lbracket, tmp, rat,  flag);
    }

    return 0;
}
