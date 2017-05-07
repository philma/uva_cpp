#include <iostream>
#include <string>

using namespace std;

struct Point
{
    int x;
    int y;
};

int judge(const Point& div_p, const Point& resid_p)
{
    if(div_p.x == resid_p.x
            || div_p.y == resid_p.y)
        return 0;

    if(resid_p.x < div_p.x)
        return (resid_p.y > div_p.y ? 1 : 4);
    else
        return (resid_p.y > div_p.y ? 2 : 3);
}

int main()
{
    string ans[] = {"divisa", "NO", "NE", "SE", "SO"};

    int query = 0;
    while(cin >> query && query)
    {
        Point div_p;
        cin >> div_p.x >> div_p.y;
        for(int i = 0; i < query; ++i)
        {
            Point resid_p;
            cin >> resid_p.x >> resid_p.y;
            cout << ans[judge(div_p, resid_p)] << endl;
        }
    }

    return 0;
}
