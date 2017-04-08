#include <iostream>

using namespace std;

void snail_climb(double height, double up
        , double down, double factor)
{
    int day_cnt = 0, result = 0;
    double distance = 0;
    double lost_dist = up * factor / 100;
    
    while(true)
    {
        ++day_cnt;
        distance += up;
        if(distance > height)
        {
            result = 0;
            break;
        }

        distance -= down;
        if(distance < 0)
        {
            result = 1;
            break;
        }

        up -= lost_dist;
        if(up < 0) up = 0;
    }

    cout << (result ? "failure" : "success"); 
    cout << " on day " << day_cnt << endl;
}

int main()
{
    int height = 0, up = 0;
    int down = 0, factor = 0;

    while(cin >> height >> up 
            >> down >> factor)
    {
        if(!height) break;

        snail_climb(height, up, down, factor);
    }

    return 0;
}
