#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class rectangle
{
    double length;
    double width;
    char *color;
 
public:
    rectangle(double i, double j, const char *d)
    {
        length = i;
        width = j;
        color = new char[strlen(d) + 1];
        strcpy(color, d);
    }
    rectangle()
    {
        length = 0;
        width = 0;
        color = nullptr;
    }
    rectangle(const rectangle &ob)
    {
        length = ob.length;
        width = ob.width;
        color = new char[strlen(ob.color) + 1];
        strcpy(color, ob.color);
    }
    ~rectangle()
    {
        if (color != NULL)
            delete[] color;
        color = NULL;
    }
    int getPerimeter()
    {
        return 2 * (length + width);
    }
    int getArea()
    {
        return length * width;
    }
    char *getColor()
    {
        return color;
    }
    void setColor(const char *k)
    {
        delete[] color;
        color = new char[strlen(k) + 1];
        strcpy(color, k);
    }
    void setter(rectangle &ob)
    {
        length = ob.length;
        width = ob.width;
    }
    double getlength()
    {
        return length;
    }
    double getwidth()
    {
        return width;
    }
    rectangle *clone()
    {
        rectangle *temp = new rectangle;
        temp->length = length;
        temp->width = width;
        temp->color = new char(strlen(color) + 1);
        strcpy(temp->color, color);
        return temp;
    }
};
class triangle
{
    double a;
    double b;
    double c;
    char *color;
 
public:
    triangle(double i, double j, double k, const char *d)
    {
        a = i;
        b = j;
        c = k;
        color = new char[strlen(d) + 1];
        strcpy(color, d);
    }
    triangle()
    {
        a = 0;
        b = 0;
        c = 0;
        color = nullptr;
    }
    triangle(const triangle &ob)
    {
        a = ob.a;
        b = ob.b;
        c = ob.c;
        color = new char[strlen(ob.color) + 1];
        strcpy(color, ob.color);
    }
    ~triangle()
    {
        if (color != NULL)
            delete[] color;
        color = NULL;
    }
    int getPerimeter()
    {
        return a + b + c;
    }
    int getArea()
    {
        double s = getPerimeter();
        s = s / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    char *getColor()
    {
        return color;
    }
    void setColor(const char *k)
    {
        delete[] color;
        color = new char[strlen(k) + 1];
        strcpy(color, k);
    }
    void setter(triangle &ob)
    {
        a = ob.a;
        b = ob.b;
        c = ob.c;
    }
    double geta()
    {
        return a;
    }
    double getb()
    {
        return b;
    }
    double getc()
    {
        return c;
    }
    triangle *clone()
    {
        triangle *temp = new triangle;
        temp->a = a;
        temp->b = b;
        temp->c = c;
        temp->color = new char(strlen(color) + 1);
        strcpy(temp->color, color);
        return temp;
    }
};
class circle
{
    double r;
    char *color;
 
public:
    circle(double i, const char *d)
    {
        r = i;
        color = new char[strlen(d) + 1];
        strcpy(color, d);
    }
    circle()
    {
        r = 0;
        color = nullptr;
    }
    circle(const circle &ob)
    {
        r = ob.r;
        color = new char[strlen(ob.color) + 1];
        strcpy(color, ob.color);
    }
    ~circle()
    {
        if (color != NULL)
            delete[] color;
        color = NULL;
    }
    double getPerimeter()
    {
        return 2 * 3.14 * r;
    }
    double getArea()
    {
        return 3.14 * r * r;
    }
    char *getColor()
    {
        return color;
    }
    void setColor(const char *k)
    {
        delete[] color;
        color = new char[strlen(k) + 1];
        strcpy(color, k);
    }
    void setter(circle &ob)
    {
        r = ob.r;
    }
    double getr()
    {
        return r;
    }
    circle *clone()
    {
        circle *temp = new circle;
        temp->r = r;
        temp->color = new char(strlen(color) + 1);
        strcpy(temp->color, color);
        return temp;
    }
};
 
class ShapeCollection
{
    int reccount;
    int tricount;
    int circcount;
    int rec_cap;
    int tri_cap;
    int circ_cap;
    rectangle **arr_rect;
    circle **arr_circ;
    triangle **arr_tri;
 
public:
    ShapeCollection()
    {
        reccount = tricount = circcount = 0;
        rec_cap = 1;
        tri_cap = 1;
        circ_cap = 1;
        arr_rect = new rectangle *[1];
        /*for (int i = 0; i < rec_cap; i++)
        {
            arr_rect[i] = new rectangle;
        }*/
        arr_circ = new circle *[1];
       /* for (int i = 0; i < circ_cap; i++)
        {
            arr_circ[i] = new circle;
        }*/
        arr_tri = new triangle *[1];
       /* for (int i = 0; i < tri_cap; i++)
        {
            arr_tri[i] = new triangle;
        }*/
    }
    ~ShapeCollection()
    {
        for (int i = 0; i < reccount; i++)
        {
            delete arr_rect[i];
        }
        delete[] arr_rect;
        for (int i = 0; i < circcount; i++)
        {
            delete arr_circ[i];
        }
        delete[] arr_circ;
        for (int i = 0; i < tricount; i++)
        {
            delete arr_tri[i];
        }
        delete[] arr_tri;
    }
    void resize(rectangle **r)
    {
        rectangle **temp = new rectangle *[rec_cap * 2];
       /* for (int i = 0; i < rec_cap * 2; i++)
        {
            temp[i] = new rectangle;
        }*/
        for (int i = 0; i < reccount; i++)
        {
            temp[i] = r[i]->clone();
        }
        for (int i = 0; i < rec_cap; i++)
        {
            delete r[i];
        }
        delete[] r;
        rec_cap = rec_cap * 2;
        arr_rect = temp;
    }
    void resize(triangle **r){
         triangle **temp = new triangle *[tri_cap * 2];
           /* for (int i = 0; i < tri_cap; i++)
            {
                temp[i] = new triangle;
            }*/
            for (int i = 0; i < tricount; i++)
            {
                temp[i] = r[i]->clone();
            }
            for (int i = 0; i < tri_cap; i++)
            {
                delete r[i];
            }
            delete[] r;
            tri_cap = tri_cap * 2;
            arr_tri = temp;
    }
    void resize(circle **r){
        circle **temp = new circle *[circ_cap * 2];
          /* for (int i = 0; i < circ_cap; i++)
            {
                temp[i] = new circle;
            }*/
            for (int i = 0; i < circcount; i++)
            {
                temp[i] = r[i]->clone();
            }
            for (int i = 0; i < circ_cap; i++)
            {
                delete r[i];
            }
            delete[] r;
            circ_cap = circ_cap * 2;
            arr_circ = temp;
    }
    void add(rectangle ob)
    {
        if (reccount == rec_cap)
        {
            resize(arr_rect);
        }
        arr_rect[reccount] = ob.clone();
        reccount++;
    }
    void printrectangles()
    {
        for (int i = 0; i < reccount; i++)
        {
            cout << "Rectangle " << i << ":" << " length:" << arr_rect[i]->getlength() << " width:" << arr_rect[i]->getwidth() << endl;
        }
    }
    int getrectcount()
    {
        return reccount;
    }
    void add(triangle ob)
    {
 
        if (tricount == tri_cap)
        {
          resize(arr_tri);
        }
        arr_tri[tricount] = ob.clone();
        tricount++;
    }
    void printtriangles()
    {
        for (int i = 0; i < tricount; i++)
        {
            cout << "Triangle " << i << ":" << " a:" << arr_tri[i]->geta() << " b:" << arr_tri[i]->getb() << " c:" << arr_tri[i]->getc() << endl;
        }
    }
    int gettricount()
    {
        return tricount;
    }
    void add(circle ob)
    {
 
        if (circcount == circ_cap)
        {
            resize(arr_circ);
        }
        arr_circ[circcount] = ob.clone();
        circcount++;
    }
    void printcircles()
    {
        for (int i = 0; i < circcount; i++)
        {
            cout << "Circle " << i << ":" << " radius:" << arr_circ[i]->getr() << endl;
        }
    }
    int getcirccount()
    {
        return circcount;
    }
};
int main()
{
    // Create rectangle with length, width, color
    rectangle r1(10, 20, "Red");
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
    triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create circle with radius, color
    circle c1(7, "Green");
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
    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);
 
    rectangle r2(15, 25, "Black");
    shapes.add(r2);
    triangle t2(5, 12, 13, "White");
    shapes.add(t2);
 
    cout << "Number of Rectangles: " << shapes.getrectcount() << endl;
    cout << "Number of Triangles: " << shapes.gettricount() << endl;
    cout << "Number of Circles: " << shapes.getcirccount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printrectangles();
    shapes.printtriangles();
    shapes.printcircles();
    return 0;
}