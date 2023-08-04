#include <cstring>
#include <iostream>
#include "student_csv.h"
#include "reverse.h"
#include "student.h"

using namespace std;

const string CSV_FILENAME = "students.csv";

void printStudents(Student **students, int studentCount)
{
	for (auto i = 0; i < studentCount; i++) {
		cout << students[i]->firstName << " " << students[i]->lastName  << endl;
	}
}

int main()
{
	int i = 0;
	int maxStudents = 5;
	Student **students = new Student*[maxStudents];

	processStudents(CSV_FILENAME, maxStudents, [students,&i](int id, string firstName, string lastName, string email, string address) {
		Student *student = new Student;
		setStudent(student, id, firstName, lastName, email, address);
		students[i++] = student;
	});

	printStudents(students, maxStudents);
	reverse(students, maxStudents);
	cout << endl;
	printStudents(students, maxStudents);

	for (i = 0; i < maxStudents; i++) {
		delete students[i];
	}

	delete [] students;

	return EXIT_SUCCESS;
}
