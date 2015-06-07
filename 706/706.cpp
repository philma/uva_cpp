#include <iostream>
#include <string>

using namespace std;

void print(int level, int s, int digit)
{
    int flag[10][5] = {{1, 3, 0, 3, 1}, {0, 2, 0, 2, 0}, {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {0, 3, 1, 2, 0},
                       {1, 1, 1, 2, 1}, {1, 1, 1, 3, 1}, {1, 2, 0, 2, 0}, {1, 3, 1, 3, 1}, {1, 3, 1, 2, 1}};
    if(level & 1)
    {
        if(flag[digit][level] == 1
           || flag[digit][level] == 3)
            cout << '|';
        else
            cout << ' ';

        for(int i = 0; i < s; ++i)
            cout << ' ';

        if(flag[digit][level] == 2
           || flag[digit][level] == 3)
            cout << '|';
        else
            cout << ' ';
    }
    else
    {
        cout << ' ';
        for(int i = 0; i < s; ++i)
        {
            if(flag[digit][level])
                cout << '-';
            else
                cout << ' ';
        }
        cout << ' ';
    }
}

void number_to_string(int number, string& str)
{
    do
    {
        str.insert(str.begin(), '0' + number % 10);
        number /= 10;
    }while(number);
}

int main()
{
    int s = 0, n = 0;
    while(cin >> s >> n && s + n != 0)
    {
        string number;
        number_to_string(n, number);
        for(int level = 0; level < 5; ++level)
        {
            int times = (level & 1) ? s : 1;
            for(int k = 0; k < times; ++k)
            {
                for(unsigned int i = 0; i < number.size(); ++i)
                {
                    print(level, s, number[i] - '0');
                    if(i < number.size() - 1)
                        cout << ' ';
                    else
                        cout << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
