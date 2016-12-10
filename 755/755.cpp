#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

static const char LETTER_NUM_MAP[26] = 
{'2','2','2','3','3','3','4','4','4','5','5','5'
    ,'6','6','6','7','0','7','7','8','8','8','9','9','9','0'};

void std_telephone(const string& str, string& std_str)
{
    for(size_t i = 0; i < str.size(); ++i)
    {
        if(str[i] == '-')
            continue;
        char tmp = str[i];
        if(tmp >= 'A' && tmp <= 'Z')
            tmp = LETTER_NUM_MAP[tmp - 'A'];
        std_str += tmp;
        if(std_str.size() == 3)
            std_str += '-';
    }
}

int main()
{
    int data_set_num = 0;
    cin >> data_set_num;
    while(data_set_num--)
    {
        int tp_num = 0;
        cin >> tp_num;
        getchar();
        map<string, int> tel_nums;
        for(int i = 0; i < tp_num; ++i)
        {
            string tmp, std_tel;
            getline(cin, tmp);
            std_telephone(tmp, std_tel);
            tel_nums[std_tel] += 1;
        }

        map<string, int>::iterator it = tel_nums.begin();
        bool dup = false;
        for(; it != tel_nums.end(); ++it)
        {
            if(it->second == 1) continue;
            cout << it->first << ' ' << it->second << endl;
            dup = true;
        }

        if(!dup) cout << "No duplicates." << endl;
        if(data_set_num) cout << endl;
    }

    return 0;
}
