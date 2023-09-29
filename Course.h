#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Course
{
private:
    string name;
    Faculty* faculty;
    vector<Student*> roster;
    
public:
    //Accessors
    string getName() { return name; };
    Faculty* getFaculty() { return faculty; };
    vector<Student*> getRoster() { return roster; };
    
    //Mutators
    void setName(string name) { this->name = name; };
    void setFaculty(Faculty &f) { this->faculty = &f; };
    void setRoster(vector<Student*> roster) { this->roster = roster; };
    
    //Constructor
    Course(string cName = "Na", Faculty* f = nullptr, vector<Student*> roster = {}) {
        setName(cName);
        setFaculty(*f);
        setRoster(roster);
    }
    
    //User-defined methods
    string toString();
    int findStudent(string studentName);
    bool addStudent(Student* s);
    bool removeStudent(string studname);
};

string Course::toString() {
    stringstream sout;
    sout << "Course-Faculty Information:------------------------------------------\nCourse Name: " << getName() << endl << getFaculty()->toString()
    << "\nCourse-Student Roster (" << getRoster().size() << " students)\n";
    for (int i =0; i < getRoster().size(); i++) {
        sout << getRoster().at(i)->toString() << endl;
    };
    return sout.str();
};

int Course::findStudent(string studentName) {
    int status = -1;
    for (int i = 0; i < roster.size(); i++) {
        if (roster.at(i)->getName() == studentName) {
            status = i;
            break;
        };
    };
    return status;
};

bool Course::addStudent(Student* s) {
    for (int i = 0; i < roster.size(); i++) {
        if (roster.at(i)->getName() == s->getName()) {
            return false;
        };
    };
    roster.push_back(s);
    return true;
};

bool Course::removeStudent(string studname) {
    if (findStudent(studname) != -1) {
        roster.erase(roster.begin() + findStudent(studname));
        return true;
    }
    else
        return false;
};



