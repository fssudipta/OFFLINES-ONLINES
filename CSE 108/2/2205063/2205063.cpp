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
        if (color != nullptr)
        {
            this->color = new char[strlen(color) + 1];
            strcpy(this->color, color);
        }
        else
            this->color = nullptr;
    }

    Rectangle(const Rectangle &other)
    {
        length = other.length;
        width = other.width;
        if (other.color)
        {
            color = new char[strlen(other.color) + 1];
            strcpy(color, other.color);
        }
        else
            color = nullptr;
    }

    ~Rectangle()
    {
        if (color)
            delete[] color;
    }

    Rectangle *clone() const
    {
        return new Rectangle(*this);
    }

    void setColor(const char *newColor)
    {
        if (color)
            delete[] color;
        if (newColor != nullptr)
        {
            color = new char[strlen(newColor) + 1];
            strcpy(color, newColor);
        }
        else
            color = nullptr;
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

    int getLength() const
    {
        return length;
    }

    int getWidth() const
    {
        return width;
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
        if (color != nullptr)
        {
            this->color = new char[strlen(color) + 1];
            strcpy(this->color, color);
        }
        else
        {
            this->color = nullptr;
        }
    }

    Triangle(const Triangle &other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        if (other.color != nullptr)
        {
            color = new char[strlen(other.color) + 1];
            strcpy(color, other.color);
        }
        else
        {
            color = nullptr;
        }
    }

    ~Triangle()
    {
        if (color)
            delete[] color;
    }

    Triangle *clone() const
    {
        return new Triangle(*this);
    }

    void setColor(const char *newColor)
    {
        if (color)
            delete[] color;
        if (newColor != nullptr)
        {
            color = new char[strlen(newColor) + 1];
            strcpy(color, newColor);
        }
        else
            color = nullptr;
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

    const char *getColor() const
    {
        return color;
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
        if (color != nullptr)
        {
            this->color = new char[strlen(color) + 1];
            strcpy(this->color, color);
        }
        else
        {
            this->color = nullptr;
        }
    }

    Circle(const Circle &other)
    {
        radius = other.radius;
        if (other.color)
        {
            color = new char[strlen(other.color) + 1];
            strcpy(color, other.color);
        }
        else
            color = nullptr;
    }

    ~Circle()
    {
        if (color)
            delete[] color;
    }

    Circle *clone() const
    {
        return new Circle(*this);
    }

    void setColor(const char *newColor)
    {
        if (color)
            delete[] color;
        if (newColor != nullptr)
        {
            color = new char[strlen(newColor) + 1];
            strcpy(color, newColor);
        }
        else
            color = nullptr;
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

    int getRadius() const
    {
        return radius;
    }
};

class ShapeCollection
{
    Rectangle **rectangles;
    Triangle **triangles;
    Circle **circles;
    int rectCount, triCount, circCount, rectCap, triCap, circCap;

public:
    ShapeCollection()
    {
        rectCount = triCount = circCount = 0;
        rectCap = triCap = circCap = 1;
        rectangles = new Rectangle *[rectCap];
        triangles = new Triangle *[triCap];
        circles = new Circle *[circCap];
    }

    ~ShapeCollection()
    {
        for (int i = 0; i < rectCount; i++)
            delete rectangles[i];
        for (int i = 0; i < triCount; i++)
            delete triangles[i];
        for (int i = 0; i < circCount; i++)
            delete circles[i];
        delete[] rectangles;
        delete[] triangles;
        delete[] circles;
    }

    void add(Rectangle r)
    {
        if (rectCount >= rectCap)
            resizeRectangles();
        rectangles[rectCount++] = r.clone();
    }

    void add(Triangle t)
    {
        if (triCount >= triCap)
            resizeTriangles();
        triangles[triCount++] = t.clone();
    }

    void add(Circle c)
    {
        if (circCount >= circCap)
            resizeCircles();
        circles[circCount++] = c.clone();
    }

    void resizeRectangles()
    {
        cout << "Increasing capacity of rectangles from " << rectCap << " to " << rectCap * 2 << endl;
        rectCap *= 2;
        Rectangle **temp = new Rectangle *[rectCap];
        for (int i = 0; i < rectCount; i++)
            temp[i] = rectangles[i];
        delete[] rectangles;
        rectangles = temp;
    }

    void resizeTriangles()
    {
        cout << "Increasing capacity of triangles from " << triCap << " to " << triCap * 2 << endl;
        triCap *= 2;
        Triangle **temp = new Triangle *[triCap];
        for (int i = 0; i < triCount; i++)
            temp[i] = triangles[i];
        delete[] triangles;
        triangles = temp;
    }

    void resizeCircles()
    {
        cout << "Increasing capacity of circles from" << circCap << " to " << circCap * 2 << endl;
        circCap *= 2;
        Circle **temp = new Circle *[circCap];
        for (int i = 0; i < circCount; i++)
            temp[i] = circles[i];
        delete[] circles;
        circles = temp;
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
            cout << "Rectangle " << i << ": length: " << rectangles[i]->getLength() << " width: " << rectangles[i]->getWidth() << endl;
        }
    }

    void printTriangles() const
    {
        for (int i = 0; i < triCount; i++)
        {
            cout << "Triangle " << i << ": a: " << triangles[i]->getSideA() << " b: " << triangles[i]->getSideB() << " c: " << triangles[i]->getSideC() << endl;
        }
    }

    void printCircles() const
    {
        for (int i = 0; i < circCount; i++)
        {
            cout << "Circle " << i << ": radius: " << circles[i]->getRadius() << endl;
        }
    }
};

int main()
{
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
    When constructing the ShapeCollection class, you will create dynamic for
    rectangles, triangles and circles. You have to dynamically allocate memory for this.
    */
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by value to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied. So, you have to write copy contructor so that
    memory allocation is properly done and no double free error occurs.
    */

    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);

    Rectangle r2(15, 25, "Black");
    Rectangle r3(150, 225, "Green");
    shapes.add(r2);
    shapes.add(r3);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);

    cout << endl;

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}