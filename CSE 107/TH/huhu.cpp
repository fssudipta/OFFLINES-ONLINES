#include <iostream>

using namespace std;

class Rectangle
{
    int *height, *width;

public:
    Rectangle()
    {
        height = new int;
        width = new int;
        *height = 0;
        *width = 0;
        cout << "Default constructor called" << endl;
    }
    Rectangle(int h, int w)
    {
        height = new int;
        width = new int;
        *height = h;
        *width = w;
        cout << "Parameterized constructor called" << endl;
    }

    Rectangle(const Rectangle &obj)
    {
        height = new int;
        width = new int;
        *height = *obj.height;
        *width = *obj.width;
        cout << "Copy constructor called" << endl;
    }

    ~Rectangle()
    {
        delete height;
        delete width;
        cout << "Destructor called" << endl;
    }

    int area()
    {
        return *height * *width;
    }
};

Rectangle larger(Rectangle a, Rectangle b)
{
    if (a.area() > b.area())
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{

    Rectangle r1(1, 2), r2(10, 20), r3, large;
    r3 = r1;
    cout << large.area() << endl;
    large = larger(r1, r2);
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Area of r2: " << r2.area() << endl;
    cout << "Area of r3: " << r3.area() << endl;
    cout << "Area of larger rectangle: " << large.area() << endl;

    return 0;
}