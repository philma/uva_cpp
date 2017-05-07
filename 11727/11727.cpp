#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int c = 0; c < t; ++c)
    {
        vector<int> numbers;
        for(int i = 0; i < 3; ++i)
        {
            int x = 0;
            cin >> x;
            numbers.push_back(x);
        }
        sort(numbers.begin(), numbers.end());

        cout << "Case " << c + 1 << ": ";
        cout << numbers[1] << endl;
    }

    return 0;
}
