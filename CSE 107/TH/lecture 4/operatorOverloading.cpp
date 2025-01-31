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
    friend coord operator+(coord ob1, coord ob2);
    friend coord operator+(int i, coord ob);
    friend coord operator++(coord &ob);
};

// Friend operator function to add two coord objects
coord operator+(coord ob1, coord ob2) {
    coord temp;
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}

// Friend operator function to add an integer to a coord object
coord operator+(int i, coord ob) {
    coord temp;
    temp.x = ob.x + i;
    temp.y = ob.y + i;
    return temp;
}

// Friend operator function to increment a coord object
coord operator++(coord &ob) {
    ob.x++;
    ob.y++;
    return ob;
}

int main() {
    coord obj1(10, 20), obj2(5, 15), obj3;
    obj3 = obj1 + obj2; // Uses operator+(coord, coord)
    obj3.show();
    obj3 = 10 + obj1; // Uses operator+(int, coord)
    obj3.show();
    ++obj1; // Uses operator++(coord &)
    obj1.show();
    return 0;
}
