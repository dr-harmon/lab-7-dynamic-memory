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
		// TODO
	}
}

int main()
{
	int i = 0;
	int maxStudents = 5;

	// TODO: Allocate an array of pointers to Student structs and call it "students"

	processStudents(CSV_FILENAME, maxStudents, [students,&i](int id, string firstName, string lastName, string email, string address) {
		// TODO: Allocate a new Student struct and copy the parameters to it.
		// Hint: Use the setStudent helper function.
	});

	printStudents(students, maxStudents);
	reverse(students, maxStudents);
	cout << endl;
	printStudents(students, maxStudents);

	// TODO: Free all allocated memory

	return EXIT_SUCCESS;
}
