#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int case_cnt = 0;
    int n = 0, m = 0, c = 0;
    while(cin >> n >> m >> c)
    {
        if(n == 0 && m == 0 && c == 0)
            break;
        
        ++case_cnt;
        vector<int> consumes;
        for(int i = 0; i < n; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            consumes.push_back(tmp);
        }

        int state = 0, consume = 0;
        int max_con = -1;
        for(int i = 0; i < m; ++i)
        {
            int index = 0;
            cin >> index;
            if(consume == -1) continue;

            state ^= 1 << (index - 1);
            consume += consumes[index - 1] * ((state >> (index - 1) & 1) ? 1 : -1);
            if(consume > c) consume = -1;
            if(consume > max_con) max_con = consume;
        }

        cout << "Sequence " << case_cnt << endl;
        if(consume == -1)
            cout << "Fuse was blown." << endl;
        else
        {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max_con << " amperes." << endl;
        }
        cout << endl;
    }

    return 0;
}