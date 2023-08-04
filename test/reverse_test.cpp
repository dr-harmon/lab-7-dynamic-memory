#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include "reverse.h"
#include "student.h"
#include "student_csv.h"

using namespace std;

TEST_CASE("Odd-length arrays can be reversed") {
    int arr[] = {1, 2, 3};
    reverse(arr, 3);
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 1);
}

TEST_CASE("Even-length arrays can be reversed") {
    int arr[] = {1, 2, 3, 4};
    reverse(arr, 4);
    REQUIRE(arr[0] == 4);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 2);
    REQUIRE(arr[3] == 1);
}

TEST_CASE("Empty arrays are allowed") {
    int arr[] = {};
    reverse(arr, 0);
}

const string CSV_FILENAME = "../students.csv";
const int STUDENT_COUNT = 10;

void loadStudents(Student *students, int count)
{
    int i = 0;    
	processStudents(CSV_FILENAME, count, [students,&i](int id, string firstName, string lastName, string email, string address) {
        setStudent(&students[i++], id, firstName, lastName, email, address);
	});
}

void loadStudents(Student **students, int count)
{
    // TODO
}

TEST_CASE("Arrays of structs can be reversed") {
    Student students[STUDENT_COUNT];
    loadStudents(students, STUDENT_COUNT);
    reverse(students, STUDENT_COUNT);
    for (int i = 0; i < STUDENT_COUNT; i++) {
        REQUIRE(students[i].id == STUDENT_COUNT - i);
    }

    BENCHMARK_ADVANCED("Reversing structs")(Catch::Benchmark::Chronometer meter) {
        int studentCount = countCSVRows(CSV_FILENAME);
        Student *students = new Student[studentCount];
        loadStudents(students, studentCount);
        meter.measure([&students,studentCount] {
            reverse(students, studentCount);
        });
        delete [] students;
    };
}

TEST_CASE("Arrays of pointers to structs can be reversed") {
    // TODO
    // Note: Don't forget to free all memory that you allocate!
}
