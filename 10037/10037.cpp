#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Step
{
    Step(int p1, int p2):person1(p1), person2(p2)
    {
    }

    int person1;
    int person2;
};

void process_case(const vector<int>& time)
{
    vector<Step> steps;
    int pos = time.size() - 1;
    int sum = 0;

    while(pos + 1 >= 4)
    {
        if(time[pos - 1] + time[0] < 2 * time[1])
        {
            steps.push_back(Step(time[0], time[pos]));
            sum += time[pos];
            steps.push_back(Step(time[0], 0));
            sum += time[0];
            steps.push_back(Step(time[0], time[pos - 1]));
            sum += time[pos - 1];
            steps.push_back(Step(time[0], 0));
            sum += time[0];
        }
        else
        {
            steps.push_back(Step(time[0], time[1]));
            sum += time[1];
            steps.push_back(Step(time[1], 0));
            sum += time[1];
            steps.push_back(Step(time[pos - 1], time[pos]));
            sum += time[pos];
            steps.push_back(Step(time[0], 0));
            sum += time[0];
        }
        pos -= 2;
    }

    if(pos + 1 == 3)
    {
        steps.push_back(Step(time[pos - 2], time[pos]));
        sum += time[pos];
        steps.push_back(Step(time[pos - 2], 0));
        sum += time[pos - 2];
        steps.push_back(Step(time[pos - 2], time[pos - 1]));
        sum += time[pos - 1];
    }
    else if(pos + 1 == 2)
    {
        steps.push_back(Step(time[pos - 1], time[pos]));
        sum += time[pos];
    }
    else
    {
        steps.push_back(Step(time[pos], 0));
        sum += time[pos];
    }

    cout << sum << endl;
    for(unsigned int i = 0; i < steps.size(); ++i)
    {
        cout << steps[i].person1;
        if(steps[i].person2)
            cout << " " << steps[i].person2;
        cout << endl;
    }
}

int main()
{
    int case_num = 0;
    cin >> case_num;
    while(case_num--)
    {
       int n = 0;
       cin >> n;

        vector<int> time;
        for(int i = 0; i < n; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            time.push_back(tmp);
        }

        sort(time.begin(), time.end());
        process_case(time);

        if(case_num)
            cout << endl;
    }

    return 0;
}
