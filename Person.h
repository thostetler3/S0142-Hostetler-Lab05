#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    string name, email, phone1, phone2;
    
public:
    //Destructor
    ~Person() {
        //cout << "Destructor " << name << endl;
    };
    
    //All-zero arguments constructor
    Person(string nameVal = "none", string emailVal = "none", string mainPhone = "none", string emergencyPhone = "none") {
        setName(nameVal);
        setEmail(emailVal);
        setMainPhone(mainPhone);
        setEmergencyPhone(emergencyPhone);
    };
    
    //Copy constructor
    Person(Person &p) { *this = p; };
    
    //Setters
    void setEmail(string emailVal)
    {
        for (int i = 0; i < emailVal.length(); i++)
        {
            if (!islower(emailVal[i]))
                emailVal[i] = tolower(emailVal[i]);
        }
        this->email = emailVal;
    };
    
    void setName(string nameVal) { this->name = titleCaps(nameVal); };
    
    void setEmergencyPhone(string emergencyPhone) { this->phone2 = emergencyPhone; };
    
    void setMainPhone(string mainPhone) { this->phone1 = mainPhone; };
    
    //Overloaded assigment operator
    Person& operator=(const Person &other);
    
    //Getters
    string getEmail() const { return email; };
    string getName() const { return name; };
    string getEmergencyPhone() const { return phone2; };
    string getMainPhone() const { return phone1; };
    
    //User-defined methods
    virtual string toString();
    string titleCaps(string value);
    };

    string Person::toString() {
        stringstream sout;
        sout << "Person [Name: " << getName() << ", Email: " << getEmail()
        << ", Main Phone: " << getMainPhone() << ", Emergency: " << getEmergencyPhone() << "]" << endl;
        return sout.str();
    };

     string Person::titleCaps(string pName) {
        
        //Capitalize first character
        pName[0] = toupper(pName[0]);

        //Correct the casing of subsequent characters
        for (int i = 1; i < pName.length(); i++)
        {
            if (isspace(pName[i-1]))
            {
                pName[i] = toupper(pName[i]);
            }
            else
            {
                pName[i] = tolower(pName[i]);
            }
        }
        return pName;
    };

    Person& Person::operator=(const Person &other){
        if (this != &other) {
            setName(other.name);
            setEmail(other.email);
            setMainPhone(other.phone1);
            setEmergencyPhone(other.phone2);
        }
        return *this;
    };
        
