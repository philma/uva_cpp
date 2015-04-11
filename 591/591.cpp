#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    while(cin >> n && n)
    {
        ++count;
        vector<int> numbers;
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = 0;
            cin >> x;
            sum += x;
            numbers.push_back(x);
        }

        int average = sum / n;
        int ans = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] > average)
                ans += numbers[i] - average;
        }

        cout << "Set #" << count << endl;
        cout << "The minimum number of moves is " << ans << "." << endl << endl;
    }

    return 0;
}
