#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jon,Sherwin,jonathan@sherwin.dev,35,20,10,32,SOFTWARE"
	};
	
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 011064274" << endl;
	cout << "Name: Jonathan Sherwin" << endl << endl;

	Roster classRoster;

	for (int i = 0; i < 5; i++)
	{
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++) {
		string id = classRoster.classRosterArray[i]->getStudentID();
		classRoster.printAverageDaysInCourse(id);
	}

	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	
	cout << endl;

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;
}