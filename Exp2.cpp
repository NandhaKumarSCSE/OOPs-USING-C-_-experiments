#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual string getName() = 0;
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) { radius = r; }

    float area() {
        return 3.14 * radius * radius;
    }

    string getName() {
        return "Circle";
    }
};

class Rectangle : public Shape {
    float length, breadth;
public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    float area() {
        return length * breadth;
    }

    string getName() {
        return "Rectangle";
    }
};

class Triangle : public Shape {
    float base, height;
public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float area() {
        return 0.5 * base * height;
    }

    string getName() {
        return "Triangle";
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(10, 8);

    Shape* shapes[3] = {&c, &r, &t};

    float totalArea = 0;
    float maxArea = 0;
    string largestShape;

    cout << "---- Shape Report ----\n";

    for(int i = 0; i < 3; i++) {
        float a = shapes[i]->area();

        cout << shapes[i]->getName()
             << " Area = " << a << endl;

        totalArea += a;

        if(a > maxArea) {
            maxArea = a;
            largestShape = shapes[i]->getName();
        }
    }

    cout << "\nTotal Area = " << totalArea << endl;
    cout << "Largest Shape = "
         << largestShape
         << " (" << maxArea << ")" << endl;

    return 0;
}