#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Student : public Person
{
private:
    string major;
    double gpa;
    int seniority;

public:
    //Accessors
    string getMajor() const { return major; };
    double getGPA() const { return gpa; };
    int getSeniority() const { return seniority; };

    //Mutators
    void setMajor(string m) { this->major = m; };
    void setGPA(double gpa) { this->gpa = gpa; };
    void setSeniority(int s) { this->seniority = s; };
    
    //Zero-All Arguments Constructor
    Student(string nameVal = "Na", string emailVal = "none", string mainPhone = "none", string emergencyPhone = "none", string majorVal = "Na", int seniority = 0, double gpa = 0.0)
        : Person(nameVal, emailVal, mainPhone, emergencyPhone)  {
            setMajor(majorVal);
            setGPA(gpa);
            setSeniority(seniority);
    };
    
    //Copy Constructor
    Student(Student &s) { *this = s; };
    
    //Overloaded assignment operator
    Student& operator=(const Student &other);
    
    //User-defined methods
    virtual string toString();
};

string Student::toString() {
stringstream sout;
sout << "Person [Name: " << getName() << ", Email: " << getEmail()
        << ", Main Phone: " << getMainPhone() << ", Emergency: " << getEmergencyPhone() << "]\n"
        << "Student [ Major: " << getMajor() << ", Seniority: " << getSeniority() << ", GPA: " << getGPA()
        << "]\n";
return sout.str();

};

Student& Student::operator=(const Student &other){
    if (this != &other) {
        setMajor(other.major);
        setGPA(other.gpa);
        setSeniority(other.seniority);
    }
    return *this;
};
