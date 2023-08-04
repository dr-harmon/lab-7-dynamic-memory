# Lab 7: Dynamic Memory

In this lab we will review dynamic memory operations using pointers, `new`, and `delete`.

The project is built around a single function called `reverse` that reverses the order of the elements in an array. The array could be anything: scalars, structs, or pointers. The project includes a `main` that exercises the `reverse` function, as well as some unit tests and benchmarks.

Most of the project has already been implemented. Your task is to fill in the missing pieces. Look through the project and replace any `TODO` comments with your own code. When you are finished, the `main.cpp` code should compile and run successfully, and all unit tests should pass. Be sure to run the benchmarks and compare the performance of reversing structs to reversing pointers to structs.

Remember to free all memory that you allocate! Do not leak memory.

The `students.csv` file contains random test data generated by [Mockaroo](https://www.mockaroo.com).
