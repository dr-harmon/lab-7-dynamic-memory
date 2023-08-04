#pragma once

#include <string>

const int MAX_STRING_LENGTH = 64;

struct Student {
    int id;
    char firstName[MAX_STRING_LENGTH];
    char lastName[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
};

void setStudent(Student *student, int id, std::string firstName, std::string lastName, std::string email, std::string address);
