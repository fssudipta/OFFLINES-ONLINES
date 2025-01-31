#include <iostream>
using namespace std;

class coord {
    int x, y;
public:
    coord(int a = 0, int b = 0) {
        x = a; y = b;
    }
    void show() {
        cout << x << ", " << y << endl;
    }
    int operator==(coord obj);
    int operator!=(coord obj);
    int operator&&(coord obj);
    int operator||(coord obj);
    coord operator++(); // Prefix version
    coord operator-();
    coord operator-(coord obj);
};

// Overloading relational and logical operators
int coord::operator==(coord obj) {
    return (x == obj.x) && (y == obj.y);
}

int coord::operator!=(coord obj) {
    return (x != obj.x) || (y != obj.y);
}

int coord::operator&&(coord obj) {
    return (x && obj.x) && (y && obj.y);
}

int coord::operator||(coord obj) {
    return (x || obj.x) || (y || obj.y);
}

// Overloading unary operators
coord coord::operator++() {
    ++x; ++y; 
    return *this;
}

coord coord::operator-() {
    coord temp;
    temp.x = -x; 
    temp.y = -y; 
    return temp;
}

coord coord::operator-(coord obj) {
    coord temp;
    temp.x = x - obj.x; 
    temp.y = y - obj.y; 
    return temp;
}

int main() {
    coord obj1(10, 20), obj2(5, 15), obj3;
    obj3 = obj1 - obj2; // Uses operator-(coord)
    obj3.show();
    obj3 = -obj1; // Uses operator-()
    obj3.show();
    ++obj1; // Uses operator++()
    obj1.show();
    cout << (obj1 == obj2) << endl; // Uses operator==(coord)
    cout << (obj1 != obj2) << endl; // Uses operator!=(coord)
    cout << (obj1 && obj2) << endl; // Uses operator&&(coord)
    cout << (obj1 || obj2) << endl; // Uses operator||(coord)
    return 0;
}
