//Author: Taylor Hostetler
//Goal: Use inheritance and aggregation to manage students and graduate students in a course with a faculty member.

#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Graduate Student.h"
#include "Faculty.h"
#include "Course.h"
using namespace std;

int main() {
    //Create test objects ==============================================
    Person person ("Juan Valdez", "greatCoffee@gmail.com", "555-1111", "555-0011");
    Student student ("Harry Potter", "magic@gmail.com", "555-2222", "555-0022",
    "Magical Science", 4, 3.79);
    GradStudent gradStudent ("Sheldon Cooper", "sheldon@gmail.com",
    "555-3333", "555-0033",
    "Astrophysics", 6, 3.99, "Big-Bang Theory", "Dr. Xavier");
    Faculty faculty ("Dr. Charles Xavier", "xman@gmail.com",
    "555-4444", "555-0044", "A123", "Physics");
    
    //Prepare a student list to be given to a course object
    vector<Student*> courseRoster;
    
    //POINTERS TO LOCAL VARIABLES
    GradStudent* gs = &gradStudent;
    Student* s = &student;
    Faculty* f = &faculty;
    courseRoster.push_back(s);
    courseRoster.push_back(gs);
    Student s2("Hermione Granger", "her@gmail.com", "555-5555", "555-0055", "Mathematics", 4, 4.0);
    Student* s2_ptr = &s2;
    courseRoster.push_back(s2_ptr);
    
    //create course using the pre-set student list
    Course course1 ("CS3 Java Programming", f, courseRoster);
    
    //Show course name, instructor, and roster
    cout << course1.toString() << endl;
    
    //create a new grad student
    GradStudent g2("Diana Prince", "amazon@gmail.com", "555-6666", "555-0066",
    "Architecture", 7, 0, "Lasso Bridges", "Dr. Xavier");
    GradStudent* g2_ptr = &g2;
    
    //try to add student g2 to course1
    if( course1.addStudent(g2_ptr) ) {
    cout << "Student added \n" << course1.toString();
    }
    else {
    cout << "Student " << g2_ptr->getName() << " NOT added";
    }
    //Again - try to add student g2 to course1
    if( course1.addStudent(g2_ptr) ) {
    cout << "Student added\n" << course1.toString() << endl;
    }
    else {
    cout << "Student " << g2_ptr->getName() << " NOT added" << endl;
    }
    //try to remove "Harry Potter" from course1
    if( course1.removeStudent("Harry Potter") ){
    cout << "Student Harry Potter removed!\n" << endl;
    cout << course1.toString() << endl;
    }
    else {
    cout << "Student Harry Potter not removed from roster" << endl;
    }
    //Again - try to remove "Harry Potter" from course1
    if( course1.removeStudent("Harry Potter") ){
    cout << "Student Harry Potter removed!" << endl;
    cout << course1.toString() << endl;
    }
    else {
    cout << "Student Harry Potter not removed from roster" << endl;
    }
};



