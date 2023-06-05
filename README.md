
# New Version C++ Database Project
==================================

This is a C++ project that demonstrates a simple database management system for students and instructors. It allows you to create and manipulate databases for students and instructors, with functionalities such as adding, removing, and modifying data.

## The Project Structure
==========================

The project consists of the following files and directories:

- `src/`: Directory containing the source code files.
- `obj/`: Directory to store the compiled object files.
- `bin/`: Directory to store the compiled executable file.
- `main.cpp`: The main file that contains the user interface and entry point of the program.
- `Makefile`: A makefile to compile and build the project.

The project is structured using separate header and implementation files for the classes involved:

- `Course.h` and `Course.cpp`: Defines the `Course` class with fields and operations related to a course.
- `Student.h` and `Student.cpp`: Defines the `Student` class with fields and operations related to a student.
- `Instructor.h` and `Instructor.cpp`: Defines the `Instructor` class with fields and operations related to an instructor.
- `StudentDB.h` and `StudentDB.cpp`: Defines the `StudentDB` class, a double-linked list of `Student` objects.
- `InstructorDB.h` and `InstructorDB.cpp`: Defines the `InstructorDB` class, a double-linked list of `Instructor` objects.
- `User.h` and `User.cpp`: Defines the `User` class with attributes and methods related to user authentication.

## Compiling and Running the Project
================================

To compile the project, follow these steps:

1. Make sure you have a C++ compiler (e.g., g++) and the GNU Make utility installed on your system.
2. Open a terminal (Linux/Unix Users and MacOS Users or command prompt (Windows US) and navigate to the project directory.
3. Run the command `make` to compile the source code.
4. Once the compilation is successful, an executable file named `main` will be generated in the `bin/` directory.

To run the program, use the following command:

```
./bin/main
```

The program will display a user interface where you can interact with the database. You will be prompted to enter a username and password for authentication. By default, the admin username is "admin" and the password is "password". Note that the admin credentials are stored in plain text for demonstration purposes and pose a security risk.

After successful authentication, you will have access to the menu options to display the student database, display the instructor database, add a student, add an instructor, or exit the program. You can choose the appropriate options and follow the instructions to perform the desired actions.

Notes
=====================
- This project is a simplified demonstration of a database management system and may not include all the robustness and error handling expected in a production system. It is intended for educational purposes.
- The user interface and functionalities can be extended and customized based on your specific requirements.
- Feel free to modify the source code and expand upon the project to add additional features or improve its functionality.

