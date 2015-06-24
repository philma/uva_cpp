#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    while(cin >> n)
    {
        vector<int> numbers;
        for(int i = 0; i < n; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            numbers.push_back(tmp);
        }

        set<int> diffs;
        for(int i = 0; i < n - 1; ++i)
        {
            int diff = numbers[i] - numbers[i + 1];
            diff = diff < 0 ? (diff * -1) : diff;
            if(diffs.find(diff) == diffs.end())
                diffs.insert(diff);
        }

        if(n == 1 || (*(diffs.begin()) == 1
                      && *(diffs.rbegin()) == n - 1
                      && diffs.size() == n - 1))
        {
            cout << "Jolly" << endl;
        }
        else
            cout << "Not jolly" << endl;
    }

    return 0;
}
