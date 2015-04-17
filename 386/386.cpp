#include <iostream>
#include <cmath>

using namespace std;

static const int MAX_A = 200;

int judge_cube(int x)
{
    int low = 1, high = MAX_A < x ? MAX_A : x;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int tmp = mid*mid*mid;
        if(tmp == x)
            return mid;
        else if(tmp > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return 0;
}

int main()
{
    for(int a = 2; a <= MAX_A; ++a)
    {
        for(int b = 2; b < a; ++b)
        {
            for(int c = b + 1; c < a; ++c)
            {
                int reminder = a*a*a - (b*b*b + c*c*c);
                if(reminder <= 0) continue;

                int tmp = judge_cube(reminder);
                if(tmp == 0|| !(tmp > b && tmp > c))
                    continue;
                cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << tmp << ")" << endl;
            }
        }
    }

    return 0;
}
