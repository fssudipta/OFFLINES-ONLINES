#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Rectangle
{
    int length, width;
    char *color;

public:
    Rectangle() {} // Default constructor

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

    int getPerimeter() const
    {
        return 2 * (length + width);
    }

    int getArea() const
    {
        return length * width;
    }

    const char *getColor() const
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getLength() const
    {
        return length;
    }

    int getWidth() const
    {
        return width;
    }

    void copyFrom(const Rectangle &change)
    {
        length = change.length;
        width = change.width;
        setColor(change.color);
    }
};

class Triangle
{
    int a, b, c;
    char *color;

public:
    Triangle() {} // Default constructor

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

    int getPerimeter() const
    {
        return a + b + c;
    }

    double getArea() const
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    const char *getColor() const
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getSideA() const
    {
        return a;
    }

    int getSideB() const
    {
        return b;
    }

    int getSideC() const
    {
        return c;
    }

    void copyFrom(const Triangle &change)
    {
        a = change.a;
        b = change.b;
        c = change.c;
        setColor(change.color);
    }
};

class Circle
{
    int radius;
    char *color;

public:
    Circle() {} // Default constructor

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

    double getPerimeter() const
    {
        return 2 * 3.14 * radius;
    }

    double getArea() const
    {
        return 3.14 * radius * radius;
    }

    const char *getColor() const
    {
        return color;
    }

    void setColor(const char *newColor)
    {
        free(color);
        color = (char *)malloc(strlen(newColor) + 1);
        strcpy(color, newColor);
    }

    int getRadius() const
    {
        return radius;
    }

    void copyFrom(const Circle &change)
    {
        radius = change.radius;
        setColor(change.color);
    }
};

class ShapeCollection
{
    Rectangle rectangles[100];
    Triangle triangles[100];
    Circle circles[100];
    int rectCount, triCount, circCount;

public:
    ShapeCollection()
    {
        rectCount = triCount = circCount = 0;
    }

    void addRectangle(const Rectangle &r)
    {
        rectangles[rectCount++].copyFrom(r); // Use copyFrom to copy data safely
    }

    void addTriangle(const Triangle &t)
    {
        triangles[triCount++].copyFrom(t);
    }

    void addCircle(const Circle &c)
    {
        circles[circCount++].copyFrom(c); 
    }

    int getRectCount() const
    {
        return rectCount;
    }

    int getTriCount() const
    {
        return triCount;
    }

    int getCircCount() const
    {
        return circCount;
    }

    void printRectangles() const
    {
        for (int i = 0; i < rectCount; i++)
        {
            cout << "Rectangle " << i << ": length: " << rectangles[i].getLength() << " width: " << rectangles[i].getWidth() << endl;
        }
    }

    void printTriangles() const
    {
        for (int i = 0; i < triCount; i++)
        {
            cout << "Triangle " << i << ": a: " << triangles[i].getSideA() << " b: " << triangles[i].getSideB() << " c: " << triangles[i].getSideC() << endl;
        }
    }

    void printCircles() const
    {
        for (int i = 0; i < circCount; i++)
        {
            cout << "Circle " << i << ": radius: " << circles[i].getRadius() << endl;
        }
    }
};

int main()
{
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "-----------------------------------" << endl;

    // Create triangle with a, b, c, color (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "---------------------------------------" << endl;

    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "-----------------------------------" << endl;

    ShapeCollection shapes;
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
    cout << "-------------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}
