
#  C++ Student Database Mock

This C++ code is a Student Database Management System that allows you to perform various operations on student records and their associated courses. The code utilizes classes and templates to store and manipulate student and course data.

## Features

- Add a new student to the database with their name, date of birth, and major.
- Insert courses for a specific student, including course ID, department, semester, and grade.
- Update student information such as name, date of birth, and major.
- Update course information for a student, including course name, department, semester, and grade.
- Delete a student from the database.
- Delete a course for a specific student.
- Print the student records along with their associated courses.

## Getting Started

To use this code, follow the steps below:

1) Clone the repository or copy the code into your local development environment.
2) Compile the code using a C++ compiler.
3) Run the compiled executable file.

## Code Structure

- `StudentDB.h`: Header file containing the declarations of the StudentDB class and its member functions.
- `StudentDB.cpp`: Implementation file containing the definitions of the StudentDB class member functions.
- `Student.h`: Header file containing the declarations of the Student and Course classes and their member functions.
- `Student.cpp`: Implementation file containing the definitions of the Student and Course class member functions.
- `main.cpp`: The main driver code that initializes the database, performs operations on student records and courses, and provides a menu-driven interface.

## Usage

The code provides a menu-driven interface where you can choose various options to perform operations on the student database. Here are the available menu options:

1) Print all student records along with their courses.
2) Search for a student by name and display their record along with courses.
3) Update a student's course information (name, department, semester, grade).
4) Update a student's record (name, date of birth, major).
5) Add a new student to the database.
6) Add a course for a specific student.
7) Delete a student from the database.
8) Delete a course for a specific student.
9) Exit the program.

Simply enter the corresponding option number to perform the desired operation. You will be prompted for input according to the chosen operation.

## Example

Here's an example scenario of using the code:

1) Choose option 1 to print all student records along with their courses.
2) Choose option 5 to add a new student.
3) Enter the student's name, date of birth, and major.
4) Repeat steps 2-3 to add more students.
5) Choose option 6 to add a course for a specific student.
6) Enter the student's name, course details (ID, department, semester, grade).
7) Repeat step 6 to add more courses for different students.
8) Choose other options to update, search, or delete students and their courses.
9) Finally, choose option 9 to exit the program.

