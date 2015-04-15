#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

bool number_equal(double lhs, double rhs)
{
    return fabs(lhs - rhs) <= 1E-10;
}

class Point
{
public:
    Point():x(0), y(0){}
    Point(double xx, double yy):x(xx), y(yy){}

public:
    double x;
    double y;
};

class Line
{
public:
    Line(const Point& point1, const Point& point2)
    {
        if(number_equal(point1.x, point2.x))
        {
            a = 1;
            b = 0;
            c = -point1.x;
        }
        else
        {
            a = (point2.y - point1.y) / (point1.x - point2.x);
            b = 1;
            c = (point1.y * point2.x - point1.x * point2.y) / (point1.x - point2.x);
        }
    }

    bool parallel(const Line& line) const
    {
        return number_equal(a, line.a)
                && number_equal(b, line.b);
    }

    bool same(const Line& line) const
    {
        return parallel(line) && number_equal(c, line.c);
    }

    void intersection_point(const Line& line, Point& point) const
    {
        if(number_equal(b, 0))
        {
            point.x = -c;
            point.y = line.a * c - line.c;
        }
        else if(number_equal(line.b, 0))
        {
            point.x = -line.c;
            point.y = a * line.c - c;
        }
        else
        {
            point.x = (line.c - c) / (a - line.a);
            point.y = (c * line.a - a * line.c) / (a - line.a);
        }
    }

public:
    double a;
    double b;
    double c;
};

int main()
{
    int n = 0;
    vector<Line> lhs_lines;
    vector<Line> rhs_lines;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        double x1 = 0, y1 = 0;
        double x2 = 0, y2 = 0;
        double x3 = 0, y3 = 0;
        double x4 = 0, y4 = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Line lhs_line(Point(x1, y1), Point(x2, y2));
        Line rhs_line(Point(x3, y3), Point(x4, y4));
        lhs_lines.push_back(lhs_line);
        rhs_lines.push_back(rhs_line);
    }

    cout << "INTERSECTING LINES OUTPUT" << endl;
    for(int i = 0; i < n; ++i)
    {
        if(lhs_lines[i].parallel(rhs_lines[i]))
        {
            if(lhs_lines[i].same(rhs_lines[i]))
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
        }
        else
        {
            Point point;
            lhs_lines[i].intersection_point(rhs_lines[i], point);
            cout << "POINT ";
            printf("%0.2lf %0.2lf\n", point.x, point.y);
        }
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
