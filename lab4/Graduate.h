#pragma once

#include "Student.h"
#include <iostream>

class Graduate : public Student
{
public:
	Graduate();
	Graduate(const int age, const  char* name, const char* surname);
	Graduate(const int age, const char* name, const char* surname, const list<int> marks);
	int getAge() override;
	void setAge(int newAge) override;
	int getNumberOfCourse() override;
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