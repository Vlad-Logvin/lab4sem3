#include "Graduate.h"

Graduate::Graduate()
{
    name = nullptr;
    surname = nullptr;
    this->numberOfCourse = 5;
    this->numberOfMarks = 0;
    this->averageMark = 0.0;
}

Graduate::Graduate(const int age, const char* name, const char* surname)
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
    this->numberOfCourse = 5;
    this->numberOfMarks = 0;
    this->averageMark = 0.0;
}

Graduate::Graduate(const int age, const char* name, const char* surname, const list<int> marks) : Graduate(age, name, surname)
{
    for (auto a = marks.begin(); a != marks.end(); ++a)
    {
        this->marks.push_back(*a);
        numberOfMarks++;
        averageMark += static_cast<double>(*a);
    }
    averageMark /= static_cast<double>(numberOfMarks);
}

int Graduate::getAge()
{
    return this->age;
}

void Graduate::setAge(int newAge)
{
    this->age = newAge;
}

int Graduate::getNumberOfCourse()
{
    return this->numberOfCourse;
}

char* Graduate::getName()
{
    return this->name;
}

void Graduate::setName(char* newName)
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

char* Graduate::getSurname()
{
    return this->surname;
}

void Graduate::setSurname(char* newSurname)
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

void Graduate::addMark(int newMark)
{
    this->marks.push_back(newMark);
    averageMark *= static_cast<double>(numberOfMarks);
    numberOfMarks++;
    averageMark += static_cast<double>(newMark);
    averageMark /= static_cast<double>(numberOfMarks);
}

bool Graduate::getType()
{
    return false;
}

const char* Graduate::getNameType()
{
    return "Graduate";
}

void Graduate::showOwnInformation()
{
    if (name != nullptr && surname != nullptr)
    {
        cout << getNameType() << endl
            << " Number of course: " << numberOfCourse << endl
            << "Name: " << name << endl
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

void Graduate::showMarks()
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
