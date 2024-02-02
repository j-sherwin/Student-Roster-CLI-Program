#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
	Student(string id, string fName, string lName, string email, int age, int classOne, int classTwo, int classThree, DegreeProgram degree);
	~Student();
	
	void print();

	//Getters Below
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int getDaysInClass(int index);
	DegreeProgram getDegree();

	//Setters Below
	void setStudentID(string id);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInClass(int index, int days);
	void setDegreeProgram(DegreeProgram degree);


private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInClass[3];
	DegreeProgram degree;

};

