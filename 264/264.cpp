#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number = 0;
    while(cin >> number)
    {
        int n = (sqrt(static_cast<double>(number) * 8 + 1) - 1)/2;

        int row = 0, col = 0;
        if(n * (n + 1) == 2 * number)
        {
            row = n;
            col = n;
        }
        else
        {
            row = n + 1;
            col = number - (n * (n + 1) / 2);
        }

        if(row & 1)
        {
            cout << "TERM " << number << " IS " << row - (col - 1) << "/" << col;
        }
        else
        {
            cout << "TERM " << number << " IS " << col << "/" << row - (col - 1);
        }
        cout << endl;
    }

    return 0;
}
