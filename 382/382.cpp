#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int judge_number(int n)
{
    int sum = 0;
    for(int i = 1; (i * i) <= n; ++i)
    {
        if(n % i != 0) continue;

        sum += i;
        if(i * i != n)
            sum += n / i;
    }
    sum -= n;

    return (sum < n ? -1 : (sum == n ? 0 : 1));
}

int main()
{
    vector<int> numbers;

    int x = 0;
    while(cin >> x && x != 0)
        numbers.push_back(x);

    cout << "PERFECTION OUTPUT" << endl;
    for(int i = 0; i < numbers.size(); ++i)
    {
        cout << right << setw(5) << numbers[i] << "  ";
        int result = judge_number(numbers[i]);
        if(result == -1)
            cout << "DEFICIENT";
        else if(result == 0)
            cout << "PERFECT";
        else
            cout << "ABUNDANT";
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
