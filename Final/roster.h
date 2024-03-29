#pragma once
#include <string>
#include "student.h"

using namespace std;

class Roster
{
public:
	Roster();
	~Roster();
	Student* classRosterArray[5];
	void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);


private:
	int arrayIndex;
};

