#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

Roster::Roster()
{
	//Intilializes arrayIndex to 0 which is used for indicating the array index when creating new student objects
	arrayIndex = 0;
}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete classRosterArray[i];
	}
	

	cout << "DONE." << endl;
}

void Roster::parse(string studentData)
{
	size_t right = studentData.find(",");
	string studentID = studentData.substr(0, right);

	size_t left = right + 1;
	right = studentData.find(",", left);
	string firstName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string lastName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string emailAddress = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	int age = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse1 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse2 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse3 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	string degree = studentData.substr(left, right - left);

	//Sets enum DegreeProgram based on degree substring
	DegreeProgram degreeProgram = SECURITY;
	if (degree == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (degree == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	//Creates new Student object in pointer array.  arrayIndex is incremented by 1 each time the add function is called in order to move to the next array index for the next created object.
	classRosterArray[arrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	arrayIndex++;
}

void Roster::remove(string studentID)
{
	cout << "Removing " << studentID << ":" << endl << endl;
	bool validID = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i]->setStudentID("");
			validID = true;
			break;
			}
	}

	if (!validID) {
		cout << "The student with the ID: " << studentID << " was not found." << endl << endl;
	}
}

void Roster::printAll()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getStudentID() != "") {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	int avgDays;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int class1 = classRosterArray[i]->getDaysInClass(0);
			int class2 = classRosterArray[i]->getDaysInClass(1);
			int class3 = classRosterArray[i]->getDaysInClass(2);
			avgDays = (class1 + class2 + class3) / 3;
		}
	}
	cout << "Student ID: " << studentID << "," << " average days in course is: " << avgDays << endl;
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:" << endl << endl;

	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmail();

		size_t required = email.find(".");
		if (required == string::npos) {
			cout << email << " - " << "is invalid." << endl;
			continue;
		}

		required = email.find("@");
		if (required == string::npos) {
			cout << email << " - " << "is invalid." << endl;
			continue;
		}

		required = email.find(" ");
		if (required != string::npos) {
			cout << email << " - " << "is invalid." << endl;
			continue;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Showing students in degree program: ";
	if (degreeProgram == SECURITY) {
		cout << "SECURITY" << endl << endl;
	}
	else if (degreeProgram == NETWORK) {
		cout << "NETWORK" << endl << endl;
	}
	else if (degreeProgram == SOFTWARE) {
		cout << "SOFTWARE" << endl << endl;
	}
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegree() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

