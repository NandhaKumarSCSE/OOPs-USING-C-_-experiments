#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    int marks;

public:
    Student(int r, string n, int m) {
        roll = r;
        name = n;
        marks = m;
        cout << "Constructor called" << endl;
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << (marks >= 90 ? 'A' : marks >= 75 ? 'B' : 'C') << endl;
    }

    ~Student() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s1(14, "Ravi", 92);
    Student s2(15, "Mahesh", 98);

    s1.display();
    s2.display();

    return 0;
}