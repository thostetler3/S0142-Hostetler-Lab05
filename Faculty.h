#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Faculty : Person
{
private:
    string officeNum, department;
    
public:
    //Accessors
    string getOfficeNum() const { return officeNum; };
    string getDepartment() const { return department; };
    
    //Mutators
    void setOfficeNum(string num) { this->officeNum = num; };
    void setDepartment(string d) { this->department = d; };
    
    //Constructor
    Faculty(string nameVal = "Na", string emailVal = "none", string mainPhone = "none", string emergencyPhone = "none", string officeNum = "", string department = 0) : Person(nameVal, emailVal, mainPhone, emergencyPhone)  {
        setOfficeNum(officeNum);
        setDepartment(department);
    };
    
    //Copy Constructor
    Faculty(Faculty &f) { *this = f; };
        
    //Overloaded assignment operator
    Faculty& operator=(const Faculty &other);
    
    //User-defined methods
    string toString();
};

string Faculty::toString() {
    stringstream sout;
    sout << "Person [Name: " << getName() << ", Email: " << getEmail()
         << ", Main Phone: " << getMainPhone() << ", Emergency: " << getEmergencyPhone() << "]\n"
         << "Office Number: " << getOfficeNum() << "\nDepartment: " << getDepartment() << endl;
    return sout.str();
};

Faculty& Faculty::operator=(const Faculty &other){
    if (this != &other) {
        setOfficeNum(other.officeNum);
        setDepartment(other.department);
    }
    return *this;
};
