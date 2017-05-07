#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int row = 0, col = 0;
        cin >> row >> col;
        row -= 2;
        col -= 2;
        row = row / 3 + (row % 3 ? 1 : 0);
        col = col / 3 + (col % 3 ? 1 : 0);
        cout << row * col << endl;
    }

    return 0;
}
