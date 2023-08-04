#include "student.h"

using namespace std;

void setStudent(Student *student, int id, string firstName, string lastName, string email, string address)
{
    student->id = id;
    strncpy(student->firstName, firstName.c_str(), MAX_STRING_LENGTH);
    strncpy(student->lastName, lastName.c_str(), MAX_STRING_LENGTH);
    strncpy(student->email, email.c_str(), MAX_STRING_LENGTH);
    strncpy(student->address, address.c_str(), MAX_STRING_LENGTH);
}
