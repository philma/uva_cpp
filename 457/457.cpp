#include <iostream>
#include <vector>

using namespace std;

static const int DAY_NUM = 50;
static const int DNA_PRO_NUM = 10;
static const int DISH_NUM = 40;

int main()
{
    int cases = 0;
    cin >> cases;
    while(cases--)
    {
        vector<int> dna_pros;
        for(int i = 0; i < DNA_PRO_NUM; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            dna_pros.push_back(tmp);
        }

        vector<int> even_day_dish(DISH_NUM, 0);
        vector<int> odd_day_dish(DISH_NUM, 0);
        even_day_dish[19] = 1;
        for(int i = 0; i < DAY_NUM; ++i)
        {
            const vector<int>& read_dish = i & 1 ? odd_day_dish : even_day_dish;
            vector<int>& write_dish = i & 1 ? even_day_dish : odd_day_dish;

            for(int j = 0; j < DISH_NUM; ++j)
            {
                int k = read_dish[j];
                if(j >= 1) k += read_dish[j - 1];
                if(j <= DISH_NUM - 2) k += read_dish[j + 1];
                write_dish[j] = dna_pros[k];

                if(read_dish[j] == 0)
                    cout << ' ';
                else if(read_dish[j] == 1)
                    cout << '.';
                else if(read_dish[j] == 2)
                    cout << 'x';
                else
                    cout << 'W';
            }
            cout << endl;
        }

        if(cases) cout << endl;
    }

    return 0;
}
