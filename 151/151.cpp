#include <iostream>
#include <cstring>

static const int MAX_N = 100;

using namespace std;

int last_one(int n, int m)
{
    int flag[MAX_N];
    memset(flag, 0, sizeof(flag));

    int pos = 0, last = 0, total = n;

    --total, flag[0] = 1;
    while(total != 0)
    {
       for(int count = 0; ; pos = (pos + 1) % n)
       {
           if(!flag[pos])
               ++count;
           if(count == m)
           {
               flag[pos] = 1;
               --total;
               if(total == 0)
                   last = pos + 1;
               break;
           }
       }
    }

    return last;
}

int main()
{
    int n;

    while((cin >> n) && n != 0)
    {
        int m = 1;
        for(; last_one(n, m) != 13; ++m);

        cout << m << endl;
    }

    return 0;
}
