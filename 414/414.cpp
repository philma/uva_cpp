#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

static const int COL_LEN = 25;

int main()
{
    int n = 0;
    while(cin >> n && n)
    {
        getchar();
        string line;
        int min_space = COL_LEN;
        int total_space = 0;
        for(int i = 0; i < n; ++i)
        {
            getline(cin, line);

            int cnt_space = 0;
            for(int j = 0; j < line.length(); ++j)
            {
                if(line[j] == ' ') ++cnt_space;
            }

            if(cnt_space < min_space)
                min_space = cnt_space;
            total_space += cnt_space;
        }
        cout << total_space - min_space * n << endl;
    }

    return 0;
}