#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int num = 0;
    while(cin >> num && num)
    {
        vector<double> expense;
        double sum = 0;
        for(int i = 0; i < num; ++i)
        {
            double tmp = 0;
            cin >> tmp;
            sum += tmp;
            expense.push_back(tmp);
        }

        double average = static_cast<int>(sum / num * 100 + 0.5) / 100.0;
        double more_ans = 0, less_ans = 0;
        for(int i = 0; i < num; ++i)
        {
            if(expense[i] > average)
                more_ans += expense[i] - average;
            else
                less_ans += average - expense[i];
        }

        double ans = (more_ans < less_ans ? more_ans : less_ans);

        cout << "$" << setprecision(2) << setiosflags(ios::fixed)
             << ans << endl;
    }

    return 0;
}
