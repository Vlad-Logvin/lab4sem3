#pragma once

#include "Student.h"
#include <iostream>

class SeniorStudent : public Student
{
public:
	SeniorStudent();
	SeniorStudent(const int age, const  char* name, const char* surname, const int numberOfCourse);
	SeniorStudent(const int age, const char* name, const char* surname, const int numberOfCourse, const list<int> marks);
	int getAge() override;
	void setAge(int newAge) override;
	int getNumberOfCourse() override;
	void setNumberOfCourse(int newNumberOfCourse);
	char* getName() override;
	void setName(char* newName) override;
	char* getSurname() override;
	void setSurname(char* newSurname) override;
	void addMark(int newMark) override;
	bool getType() override;
	const char* getNameType();
	void showOwnInformation() override;
	void showMarks() override;
};