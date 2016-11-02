#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class Point
{
public:
    Point(double x_, double y_, double z_)
        :x(x_), y(y_), z(z_)
    {}

    double distance(const Point& point)
    {
        double tmp = 0;
        tmp += (x - point.x) * (x - point.x);
        tmp += (y - point.y) * (y - point.y);
        tmp += (z - point.z) * (z - point.z);
        return sqrt(tmp);
    }

private:
    double x;
    double y;
    double z;
};

int main()
{
    vector<Point> points;
    int x = 0, y = 0, z = 0;
    while(cin >> x >> y >> z)
    {
        if(x == 0 && y == 0 && z == 0)
            break;

        Point p(x, y, z);
        points.push_back(p);
    }

    vector<int> counts(10, 0);
    for(unsigned int i = 0; i < points.size(); ++i)
    {
        double min_dist = -2;
        for(unsigned int j = 0; j < points.size(); ++j)
        {
            if(i == j) continue;
            double dist = points[i].distance(points[j]);
            if(min_dist < 0 || dist < min_dist)
                min_dist = dist;
        }

        int dist = static_cast<int>(min_dist);
        if(dist >= 0 && dist <= 9)
            ++counts[dist];
    }

    for(unsigned int i = 0; i < counts.size(); ++i)
        cout << setw(4) << counts[i];
    cout << endl;

    return 0;
}
