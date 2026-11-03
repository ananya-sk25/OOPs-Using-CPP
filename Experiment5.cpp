#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
using namespace std; 
 
class Student { 
public: 
    string name; 
    int mark; 
    char grade; 
}; 
 
int main() { 
    int n, passMark; 
    cout << "Enter number of students: "; 
    cin >> n; 
    if (n <= 0) { 
        cout << "Invalid number of students." << endl; 
        return 0; 
    } 
    vector<Student> students(n); 
    for (int i = 0; i < n; i++) { 
        cout << "Enter name and mark of student " << i + 1 << ": "; 
        cin >> students[i].name >> students[i].mark; 
    } 
    cout << "Enter a mark to search above: "; 
    cin >> passMark; 
    sort(students.begin(), students.end(), 
         [](Student a, Student b) 
         { 
             return a.mark > b.mark; 
         }); 
    transform(students.begin(), students.end(), students.begin(), 
              [](Student s) 
              { 
                  if (s.mark >= 90) 
                      s.grade = 'A'; 
                  else if (s.mark >= 75) 
                      s.grade = 'B'; 
                  else if (s.mark >= 50) 
                      s.grade = 'C'; 
                  else 
                      s.grade = 'F'; 
                  return s; 
              }); 
 
    auto it = find_if(students.begin(), students.end(), 
                      [passMark](Student s) 
                      { 
                          return s.mark > passMark; 
                      }); 
 
    int total = accumulate(students.begin(), students.end(), 0, 
                           [](int sum, Student s) 
                           { 
                               return sum + s.mark; 
                           }); 
 
    cout << "\nName\tMark\tGrade\n"; 
    for (Student s : students) 
        cout << s.name << "\t" << s.mark << "\t" << s.grade << endl; 
 
    if (it != students.end()) 
        cout << "First student scoring above " << passMark << ": " << it->name << endl; 
    else 
        cout << "No student scored above " << passMark << endl; 
 
    cout << "Total Marks: " << total << endl; 
    cout << "Average Mark: " << (float)total / n << endl;
    return 0; 
}