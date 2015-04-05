#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//static const int MAX_NUMBER = 32767;

void output_number(int number, int n)
{
    string s_number;
    do
    {
        s_number.insert(s_number.begin(), '0' + number % 10);
        number /= 10;
    }while(number != 0);

    if(s_number.size() < n)
    {
        int zero_num = n - s_number.size();
        for(int i = 0; i < zero_num; ++i)
            s_number.insert(s_number.begin(), '0');
    }

    cout << s_number << endl;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        int up_limit = pow(10.0, n) - 1;
        //up_limit = up_limit > MAX_NUMBER ? MAX_NUMBER : up_limit;

        int x = pow(10.0, n/2);
        for(int i = 0; i <= up_limit; ++i)
        {
            if((i % x + i / x) * (i % x + i / x) == i)
                output_number(i, n);
        }
    }

    return 0;
}
