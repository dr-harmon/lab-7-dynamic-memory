#include "student_csv.h"
#include "csv.h"

using namespace std;

int countCSVRows(const string& filename)
{
    io::CSVReader<0> in(filename);
    in.read_header(io::ignore_extra_column);
    int rows = 0;
    while(in.read_row()) {
        rows++;
    }
    return rows;
}

void processStudents(const string& filename, int max, function<void(int,string,string,string,string)> process)
{
    io::CSVReader<5> in(filename);
    in.read_header(io::ignore_no_column, "id", "first_name", "last_name", "email", "address");
    int id;
    string firstName, lastName, email, address;
    int count = 0;
    while (count < max && in.read_row(id, firstName, lastName, email, address)) {
        process(id, firstName, lastName, email, address);
        count++;
    }
}
