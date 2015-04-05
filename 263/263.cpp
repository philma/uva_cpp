#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void next_number(int number, int& lhs, int& rhs, int& new_number)
{
    vector<int> tmp;
    do
    {
        tmp.push_back(number % 10);
        number /= 10;
    }while(number != 0);
    sort(tmp.begin(), tmp.end());

    lhs = 0;
    for(int i = tmp.size() - 1; i >=0; --i)
        lhs = lhs * 10 + tmp[i];
    rhs = 0;
    for(int i = 0; i < tmp.size(); ++i)
        rhs = rhs * 10 + tmp[i];

    new_number = lhs - rhs;
}

int main()
{
    int number = 0;
    while(cin >> number && number != 0)
    {
        cout << "Original number was " << number << endl;

        set<int> numbers;

        int n = number;
        while(numbers.find(n) == numbers.end())
        {
            numbers.insert(n);
            int lhs = 0, rhs = 0;
            next_number(n, lhs, rhs, n);
            cout << lhs << " - " << rhs << " = " << n << endl;
        }
        cout << "Chain length " << numbers.size() << endl;
        cout << endl;
    }

    return 0;
}
