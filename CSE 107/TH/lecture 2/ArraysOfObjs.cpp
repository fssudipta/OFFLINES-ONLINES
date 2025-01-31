#include <iostream>
using namespace std;

class Circle
{
    double radius;
    double x;
    double y;

public:
    Circle(double r, double x, double y)
    {
        radius = r;
        this->x = x;
        this->y = y;
    }
    double getArea()
    {
        return 3.14 * radius * radius;
    }
    Circle(double r)
    {
        radius = r;
        x = 0;
        y = 0;
    }
};

int main()
{
    Circle crls1[2] = {7.44, 6.65};
    // Circle crls1[2] = {Circle(7.44), Circle(6.65)};
    Circle crls2[2] = {Circle(7.44, 0, 0), Circle(3.65, .5, 2.5)};
    cout << crls1[0].getArea() << endl;
    cout << crls2[0].getArea() << endl;
    return 0;
}