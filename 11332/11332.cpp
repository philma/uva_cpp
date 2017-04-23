#include <iostream>

using namespace std;

int sum_of_digit(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main()
{
    int n = 0;
    while(cin >> n && n)
    {
        int sum = n;
        while(sum >= 10)
            sum = sum_of_digit(sum);
        cout << sum << endl;
    }

    return 0;
}
