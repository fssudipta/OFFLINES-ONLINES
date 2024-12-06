#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Rectangle
{
    int length, width;
    char *color;

public:
    Rectangle(int length, int width, const char *color)
    {
        this->length = length;
        this->width = width;
        this->color = (char *)malloc(strlen(color) + 1);
        strcpy(this->color, color);
    }

    ~Rectangle()
    {
        free(color);
    }

    int getPerimeter()
    {
        return 2 * (length + width);
    }

    int getArea()
    {
        return length * width;
    }

    const char *getColor()
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
};

class Triangle
{
    int a, b, c;
    char *color;

public:
    Triangle(int a, int b, int c, const char *color)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->color = (char *)malloc(strlen(color) + 1);
        strcpy(this->color, color);
    }

    ~Triangle()
    {
        free(color);
    }

    int getPerimeter()
    {
        return a + b + c;
    }

    double getArea()
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    const char *getColor()
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getSideA()
    {
        return a;
    }
    int getSideB()
    {
        return b;
    }
    int getSideC()
    {
        return c;
    }
};

class Circle
{
    int radius;
    char *color;

public:
    Circle(int radius, const char *color)
    {
        this->radius = radius;
        this->color = (char *)malloc(strlen(color) + 1);
        strcpy(this->color, color);
    }

    ~Circle()
    {
        free(color);
    }

    double getPerimeter()
    {
        return 2 * 3.14 * radius;
    }

    double getArea()
    {
        return 3.14 * radius * radius;
    }

    const char *getColor()
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getRadius()
    {
        return radius;
    }
};

class ShapeCollection
{
    static Rectangle rectangles[100];
    static Triangle triangles[100];
    static Circle circles[100];
    int rectCount, triCount, circCount;

public:
    ShapeCollection()
    {
        rectCount = triCount = circCount = 0;
    }

    // Define add methods to copy the objects safely
    void addRectangle(const Rectangle &r)
    {
        rectangles[rectCount] = Rectangle(r.getLength(), r.getWidth(), r.getColor());
        rectCount++;
    }

    void addTriangle(const Triangle &t)
    {
        triangles[triCount] = Triangle(t.getSideA(), t.getSideB(), t.getSideC(), t.getColor());
        triCount++;
    }

    void addCircle(const Circle &c)
    {
        circles[circCount] = Circle(c.getRadius(), c.getColor());
        circCount++;
    }

    int getRectCount()
    {
        return rectCount;
    }

    int getTriCount()
    {
        return triCount;
    }

    int getCircCount()
    {
        return circCount;
    }

    void printRectangles()
    {
        for (int i = 0; i < rectCount; i++)
        {
            cout << "Rectangle " << i << ": length: " << rectangles[i].getLength() << " width: " << rectangles[i].getWidth() << endl;
        }
    }

    void printTriangles()
    {
        for (int i = 0; i < triCount; i++)
        {
            cout << "Triangle " << i << ": a: " << triangles[i].getSideA() << " b: " << triangles[i].getSideB() << " c: " << triangles[i].getSideC() << endl;
        }
    }

    void printCircles()
    {
        for (int i = 0; i < circCount; i++)
        {
            cout << "Circle " << i << ": radius: " << circles[i].getRadius() << endl;
        }
    }
};

// Define static member variables outside the class
Rectangle ShapeCollection::rectangles[100];
Triangle ShapeCollection::triangles[100];
Circle ShapeCollection::circles[100];


int main() {
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    /*
    When constructing the ShapeCollection class, you will create static arrays for 100 
    rectangles, triangles and circles. You don’t have to dynamically allocate memory for this.
    */ 
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by reference to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied, leading to double free errors when things go 
    out of scope. Once passed by reference, do not directly store the reference in 
    the array. Instead, copy the data from the reference to the array element.
    We will see better ways to handle this in the upcoming sessions.
    */ 
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);
 
    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);
 
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
 
    return 0;
}