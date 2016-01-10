#include <iostream>
#include <list>
#include <set>
#include <cstdio>

using namespace std;

const int DIGIT_NUM = 4;

int number_input()
{
    int tmp[4] = {1000, 100, 10, 1};
    int number = 0; 
    for(int i = 0; i < DIGIT_NUM; ++i)
    {
        int digit = 0;
        cin >> digit;
        number += digit * tmp[i];
    }

    return number;
}
    
/*digit_index:3 2 1 0   direction:1,-1*/
int press_button(int number, int digit_index, int direction)
{
    int tmp[4] = {1, 10, 100, 1000};
    int digit = number / tmp[digit_index] % 10;
    number -= digit * tmp[digit_index];
    digit += direction;
    if(digit < 0) digit = 9;
    if(digit > 9) digit = 0;
    number += digit * tmp[digit_index];

    return number;
}

struct WheelsInfo
{
    int number;
    int level;
};

int bfs(int init_status, int target_status, set<int>& filter)
{
    if(init_status == target_status) return 0;

    WheelsInfo wheels_info;
    wheels_info.number = init_status;
    wheels_info.level = 0;
    list<WheelsInfo> wheels_info_queue;
    wheels_info_queue.push_back(wheels_info);
    filter.insert(init_status);
    while(!wheels_info_queue.empty())
    {
        const WheelsInfo& wheels_info_front = wheels_info_queue.front();
        for(int i = 0; i < DIGIT_NUM; ++i)
        {
            int tmp[2] = {1, -1};
            for(int j = 0; j < 2; ++j)
            {
                int number_tmp = press_button(wheels_info_front.number, i, tmp[j]);
            
                if(filter.find(number_tmp) == filter.end())
                {
                    if(number_tmp == target_status)
                        return wheels_info_front.level + 1;

                    filter.insert(number_tmp);

                    WheelsInfo wheels_info_tmp;
                    wheels_info_tmp.number = number_tmp;
                    wheels_info_tmp.level = wheels_info_front.level + 1;
                    wheels_info_queue.push_back(wheels_info_tmp);
                }
            }
        }
        wheels_info_queue.pop_front();
    }

    return -1;
}

int main()
{
    int case_num = 0, count = 0;
    cin >> case_num;
    while(case_num--)
    {
        ++count;
        if(count > 1) getchar();

        int init_status = number_input();
        int target_status = number_input();

        set<int> filter;
        int forbid_num = 0;
        cin >> forbid_num;
        for(int i= 0; i < forbid_num; ++i)
        {
            int forbid_status = number_input();
            filter.insert(forbid_status);
        }

        cout << bfs(init_status, target_status, filter) 
             << endl;
    }

    return 0;
}
