#include <iostream>
#include <vector>

using namespace std;

static const int MAX_NUMBER = 100;

struct Count
{
    int i_num;
    int v_num;
    int x_num;
    int l_num;
    int c_num;
};

void count_add(Count& count, int type, int x)
{
    if(type == 2)
    {//x == 100
        ++count.c_num;
    }
    else
    {//x < 10
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        if(x < 4)
            tmp1 += x;
        else if(x == 4)
        {
            ++tmp1;
            ++tmp2;
        }
        else if(x == 5)
            ++tmp2;
        else if(x < 9)
        {
            ++tmp2;
            tmp1 += x - 5;
        }
        else
        {
            ++tmp3;
            ++tmp1;
        }

        if(type == 0)
        {
            count.i_num += tmp1;
            count.v_num += tmp2;
            count.x_num += tmp3;
        }
        else
        {
            count.x_num += tmp1;
            count.l_num += tmp2;
            count.c_num += tmp3;
        }
    }
}

void bzero_count(Count& count)
{
    count.i_num = 0;
    count.v_num = 0;
    count.x_num = 0;
    count.l_num = 0;
    count.c_num = 0;
}

void init(vector<Count>& counts) 
{
   Count count;
   bzero_count(count);

   for(unsigned int i = 0; i < counts.size(); ++i)
   {
       if( i == 99)
            count_add(count, 2, i + 1);
       else
       {
           if((i + 1) % 10)
               count_add(count, 0, (i + 1) % 10);
           if((i + 1) / 10)
               count_add(count, 1, (i + 1) / 10);
       }

       counts[i] = count;
   }
}

int main()
{
    Count count;
    bzero_count(count);
    vector<Count> counts(MAX_NUMBER, count);

    init(counts);

    int n;
    while((cin >> n) && n)
    {
        cout << n << ":";
        cout << " " << counts[n - 1].i_num << " i,";
        cout << " " << counts[n - 1].v_num << " v,";
        cout << " " << counts[n - 1].x_num << " x,";
        cout << " " << counts[n - 1].l_num << " l,";
        cout << " " << counts[n - 1].c_num << " c" << endl;
    }

    return 0;
}
