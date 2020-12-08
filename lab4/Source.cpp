#include "Graduate.h"
#include "SeniorStudent.h"

int main()
{
	list<int> marks;
	marks.push_back(10);
	marks.push_back(9);
	marks.push_back(10);

	Student* student = new Graduate(18, "Vlad", "Logvin", marks);

	student->showOwnInformation();

	cout << endl << endl;

	list<int> marks2;
	marks2.push_back(7);
	marks2.push_back(3);
	marks2.push_back(6);

	Student* student2 = new SeniorStudent(18, "NotVlad", "NotLogvin", 4, marks2);

	student2->showOwnInformation();

	delete student;
	delete student2;
	
	return 0;
}