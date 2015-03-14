#include <iostream>
#include <vector>

using namespace std;

static const int MAX_LEN = 10000;

int main()
{
    vector<int> coordinate(MAX_LEN, 0);
    int left = 0, height = 0, right = 0;
    int start = -1, dest = -1;

    while(cin >> left >> height >> right)
    {
        if(start == -1) start = left;
        if(right > dest) dest = right;

        for(int i = left; i < right; ++i)
        {
            if(height > coordinate[i])
                coordinate[i] = height;
        }
    }

    for(int i = start; i <= dest; ++i)
    {
        if(i == start)
            cout << i << " " << coordinate[i];
        else if(coordinate[i] != coordinate[i - 1])
            cout << " " << i << " " << coordinate[i];
    }
    cout << endl;

    return 0;
}
