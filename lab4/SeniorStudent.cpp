#include "SeniorStudent.h"

SeniorStudent::SeniorStudent()
{
	name = nullptr;
	surname = nullptr;
	this->numberOfCourse = 5;
	this->numberOfMarks = 0;
	this->averageMark = 0.0;
}

SeniorStudent::SeniorStudent(const int age, const char* name, const char* surname, const int numberOfCourse)
{
	this->age = age;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
	{
		this->name[i] = name[i];
	}
	this->name[strlen(name)] = '\0';
	this->surname = new char[strlen(surname) + 1];
	for (int i = 0; i < strlen(surname); i++)
	{
		this->surname[i] = surname[i];
	}
	this->surname[strlen(surname)] = '\0';
	if (numberOfCourse <= 5 && numberOfCourse >= 1)
	{
		this->numberOfCourse = numberOfCourse;
	}
	else
	{
		this->numberOfCourse = 0;
	}
	this->numberOfMarks = 0;
	this->averageMark = 0.0;
}

SeniorStudent::SeniorStudent(const int age, const char* name, const char* surname, const int numberOfCourse, const list<int> marks) : SeniorStudent(age, name, surname, numberOfCourse)
{
	for (auto a = marks.begin(); a != marks.end(); ++a)
	{
		this->marks.push_back(*a);
		numberOfMarks++;
		averageMark += static_cast<double>(*a);
	}
	averageMark /= static_cast<double>(numberOfMarks);
}

int SeniorStudent::getAge()
{
	return this->age;
}

void SeniorStudent::setAge(int newAge)
{
	this->age = newAge;
}

int SeniorStudent::getNumberOfCourse()
{
	return this->numberOfCourse;
}

void SeniorStudent::setNumberOfCourse(int newNumberOfCourse)
{
	if (numberOfCourse > 5)
	{
		cout << "Number of course can't be more than five!" << endl;
	}
	else
	{
		this->numberOfCourse = newNumberOfCourse;
	}
}

char* SeniorStudent::getName()
{
	return this->name;
}

void SeniorStudent::setName(char* newName)
{
	if (this->name == nullptr)
	{
		delete[]this->name;
	}
	this->name = new char[strlen(newName) + 1];
	for (int i = 0; i < strlen(newName); i++)
	{
		this->name[i] = newName[i];
	}
	this->name[strlen(newName)] = '\0';
}

char* SeniorStudent::getSurname()
{
	return this->surname;
}

void SeniorStudent::setSurname(char* newSurname)
{
	if (this->surname == nullptr)
	{
		delete[]this->surname;
	}
	this->surname = new char[strlen(newSurname) + 1];
	for (int i = 0; i < strlen(newSurname); i++)
	{
		this->surname[i] = newSurname[i];
	}
	this->surname[strlen(newSurname)] = '\0';
}

void SeniorStudent::addMark(int newMark)
{
	this->marks.push_back(newMark);
	averageMark *= static_cast<double>(numberOfMarks);
	numberOfMarks++;
	averageMark += static_cast<double>(newMark);
	averageMark /= static_cast<double>(numberOfMarks);
}

bool SeniorStudent::getType()
{
	return true;
}

const char* SeniorStudent::getNameType()
{
	return "SeniorStudent";
}

void SeniorStudent::showOwnInformation()
{
	if (name != nullptr && surname != nullptr)
	{
		cout << getNameType() << endl;
		if (numberOfCourse != 0)
		{
			cout << "Number of course: " << numberOfCourse << endl;
		}
		else
		{
			cout << "Number of course not specified " << endl;
		}
		cout << "Name: " << name << endl
			<< "Surname: " << surname << endl
			<< "Age: " << age << endl;
		showMarks();
		cout << "Number of marks: " << numberOfMarks << endl
			<< "Average mark: " << averageMark << endl;
	}
	else
	{
		cout << "Input name and surname!" << endl;
	}
}

void SeniorStudent::showMarks()
{
	if (this->marks.begin() != this->marks.end())
	{
		cout << "Marks: ";
		for (auto a = this->marks.begin(); a != this->marks.end(); ++a)
		{
			cout << *a << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "None" << endl;
	}
}
