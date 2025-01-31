#include <iostream>
using namespace std;

class Rectangle
{
    int *width, *height;

public:
    Rectangle(int, int);           // Parameterized constructor
    Rectangle(const Rectangle &r); // Copy constructor
    ~Rectangle();                  // Destructor
    int area() { return (*width * *height); }
};

// Parameterized constructor
Rectangle::Rectangle(int a, int b)
{
    width = new int;
    height = new int;
    *width = a;
    *height = b;
    cout << "Parameterized constructor called" << endl;
}

// Copy constructor
Rectangle::Rectangle(const Rectangle &r)
{
    width = new int;
    height = new int;
    *width = *r.width;
    *height = *r.height;
    cout << "Copy constructor called" << endl;
}

// Destructor
Rectangle::~Rectangle()
{
    delete width;
    delete height;
    cout << "Destructor called" << endl;
}

// Function to compare areas and return the larger rectangle
Rectangle &larger(Rectangle& recta, Rectangle& rectb)
{
    if (recta.area() > rectb.area())
        return recta;
    else
        return rectb;
}

int main()
{
    Rectangle recta(3, 4);
    Rectangle rectb(5, 6);
    Rectangle rectc = recta; // Calls copy constructor
    Rectangle &rect_larger = larger(recta, rectb); // Calls copy constructor and destructor 3 times
    cout << "recta area: " << recta.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    cout << "rectc area: " << rectc.area() << endl;
    cout << "rect_larger area: " << rect_larger.area() << endl;
    return 0;
}
