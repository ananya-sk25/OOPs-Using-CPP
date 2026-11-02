#include <iostream>
using namespace std;
class Shape
{
public:
    virtual float area() = 0;
    void displayArea(){
        cout << "Area: " << area() << endl;
    }
    virtual ~Shape(){}
};
class Circle : public Shape{
private:
    float radius;
public:
    Circle(float r) { radius = r;}
    float area(){
        return 3.14f * radius * radius;
    }
};
class Rectangle : public Shape{
private:
    float length, breadth;
public:
    Rectangle(float l, float b){
    length = l;
    breadth = b;
    }
    float area(){
        return length * breadth;
    }
};
class Triangle : public Shape{
private:
    float base, height;
public:
    Triangle(float b, float h){
    base = b;
    height = h;
    }
    float area(){
        return 0.5f * base * height;
    }
};
int main(){
    float r, l, b, base, height;
    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Enter base and height of triangle: ";
    cin >> base >> height;
    Circle c(r);
    Rectangle rect(l, b);
    Triangle t(base, height);
    Shape *ptr;
    cout << "\nCircle ";
    ptr = &c;
    ptr->displayArea();
    cout << "Rectangle ";
    ptr = &rect;
    ptr->displayArea();
    cout << "Triangle ";
    ptr = &t;
    ptr->displayArea();
    return 0;
}