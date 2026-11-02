#include <iostream>
using namespace std;
class Student
{
private:
    int rollNo;
    string name;
    string dept;
public:
// Constructor
    Student(int r, string n, string d){
    rollNo = r;
    name = n;
    dept = d;
    cout << "Student object created" << endl;
    }
    // Member function
    void display(){
    cout << "Roll Number: " << rollNo << endl;
    cout << "Name: " << name << endl;
    cout << "Department" << dept <<endl;
    }
    // Destructor
    ~Student(){
    cout << "Student object destroyed" << endl;
    }
};
int main()
{
    int r;
    string n,d; 
    cout << "Enter roll number: ";
    cin >> r;
    cout << "Enter name: ";
    cin >> n;
    cout<<"Enter department: ";
    cin>>d;
    Student s1(r, n,d);
    s1.display();
    return 0;
}