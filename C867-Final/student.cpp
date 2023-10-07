#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student(string id, string fName, string lName, string email, int age, int classOne, int classTwo, int classThree, DegreeProgram degree)
{
	this->studentID = id;
	this->firstName = fName;
	this->lastName = lName;
	this->email = email;
	this->age = age;
	this->daysInClass[0] = classOne;
	this->daysInClass[1] = classTwo;
	this->daysInClass[2] = classThree;
	this->degree = degree;
}

Student::~Student()
{
}

void Student::print()
{
	cout << studentID << "	" << firstName << "	" << lastName << "	" << email << "	" << age << "	{" << daysInClass[0] << "," << daysInClass[1] << "," << daysInClass[2] << "}	";
	if (degree == SECURITY) {
		cout << "SECURITY" << endl;
	}
	else if (degree == NETWORK) {
		cout << "NETWORK" << endl;
	}
	else if (degree == SOFTWARE) {
		cout << "SOFTWARE" << endl;
	}

}

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int Student::getDaysInClass(int index)
{
	return daysInClass[index];
}

DegreeProgram Student::getDegree()
{
	return degree;
}

void Student::setStudentID(string id)
{
	this->studentID = id;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysInClass(int pos, int days)
{
	this->daysInClass[pos] = days;
}


void Student::setDegreeProgram(DegreeProgram degree)
{
	this->degree = degree;
}
