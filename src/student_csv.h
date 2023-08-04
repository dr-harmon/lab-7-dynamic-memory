#pragma once

#include <functional>
#include <string>

// Returns the number of rows in the given CSV file.
int countCSVRows(const std::string& filename);

// Reads the given CSV file line by line, parses each column, and passes the data to the given callback.
// Stops when the end of the file or the given maximum is reached.
// The format of the CSV file is assumed to be student data: id, first_name, last_name, email, address
void processStudents(const std::string& filename, int max,
                     std::function<void(int,std::string,std::string,std::string,std::string)> process);
