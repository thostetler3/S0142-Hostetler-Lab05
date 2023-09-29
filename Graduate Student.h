#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class GradStudent : public Student
{
private:
    string thesis;
    string advisor;
    
public:
    //Accessors
    string getThesis() const { return thesis; };
    string getAdvisor() const { return advisor; };
    
    //Mutators
    void setThesis(string t) { this->thesis = t; };
    void setAdvisor(string a) { this->advisor = a; };
    
    //Constructor
    GradStudent(string nameVal = "Na", string emailVal = "none", string mainPhone = "none", string emergencyPhone = "none", string majorVal = "Na", int seniority = 0, double gpa = 0.0, string thesis = "Na", string advisor = "Na")
    : Student(nameVal, emailVal, mainPhone, emergencyPhone, majorVal, seniority, gpa) {
        setThesis(thesis);
        setAdvisor(advisor);
    }
    
    //Copy Constructor
    GradStudent(GradStudent &gs) { *this = gs; };
    
    //Overloaded assignment operator
    GradStudent& operator=(const GradStudent &other);
    
    //User-defined methods
    string toString();
};

string GradStudent::toString() {
    stringstream sout;
    sout << "Person [Name: " << getName() << ", Email: " << getEmail()
         << ", Main Phone: " << getMainPhone() << ", Emergency: " << getEmergencyPhone() << "]\n"
         << "Student [ Major: " << getMajor() << ", Seniority: " << getSeniority() << ", GPA: " << getGPA() << "]\n"
         << "GraduateStudent [ Thesis: " << getThesis() << ", Advisor: " << getAdvisor() << "]\n";
    return sout.str();
    
};

GradStudent& GradStudent::operator=(const GradStudent &other){
    if (this != &other) {
        setThesis(other.thesis);
        setAdvisor(other.advisor);
    }
    return *this;
};
