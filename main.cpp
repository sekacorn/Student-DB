#include <iostream>
#include <string>
#include "StudentDB.h"
#include "InstructorDB.h"
#include "User.h"

void createMockStudentDB(StudentDB& studentDB)
{
    // Create students
    Student student1("John", "Doe", "123456", "john.doe@example.com");
    Student student2("Jane", "Smith", "789012", "jane.smith@example.com");

    // Create courses
    Course course1("Math", "MATH101", "Course on Mathematics", "John Doe", "001", 90.0, "A");
    Course course2("Physics", "PHYS101", "Course on Physics", "Jane Smith", "002", 85.0, "B");

    // Add courses to students
    student1.addCourse(course1);
    student2.addCourse(course2);

    // Add students to StudentDB
    studentDB.addStudent(student1);
    studentDB.addStudent(student2);
}

void createMockInstructorDB(InstructorDB& instructorDB)
{
    // Create instructors
    Instructor instructor1("Professor", "Smith", "John", "john.smith@example.com", "Mathematics", "Experienced Math instructor");
    Instructor instructor2("Professor", "Johnson", "Jane", "jane.johnson@example.com", "Physics", "Physics expert");

    // Create courses
    Course course1("Math", "MATH101", "Course on Mathematics", "John Smith", "001", 90.0, "A");
    Course course2("Physics", "PHYS101", "Course on Physics", "Jane Johnson", "002", 85.0, "B");

    // Add courses to instructors
    instructor1.addCourse(course1);
    instructor2.addCourse(course2);

    // Add instructors to InstructorDB
    instructorDB.addInstructor(instructor1);
    instructorDB.addInstructor(instructor2);
}

void displayMenu()
{
    std::cout << "========== MENU ==========" << std::endl;
    std::cout << "1. Display Student Database" << std::endl;
    std::cout << "2. Display Instructor Database" << std::endl;
    std::cout << "3. Add Student" << std::endl;
    std::cout << "4. Add Instructor" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "==========================" << std::endl;
}

int main()
{
    // Create User
    User user;
    user.setUsername("admin");
    user.setPassword("password");
    user.setAccessPrivileges(true);

    // Create StudentDB and InstructorDB objects
    StudentDB studentDB;
    InstructorDB instructorDB;

    // Populate StudentDB with mock data
    createMockStudentDB(studentDB);

    // Populate InstructorDB with mock data
    createMockInstructorDB(instructorDB);

    // User Login
    std::string username, password;
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if (user.getUsername() == username && user.getPassword() == password && user.hasAccessPrivileges())
    {
        int choice;
        do
        {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                    std::cout << "\nStudent Database:" << std::endl;
                    studentDB.display();
                    break;
                case 2:
                    std::cout << "\nInstructor Database:" << std::endl;
                    instructorDB.display();
                    break;
                case 3:
		    std::cout << "\nAdd Student to Student Database:" << std::endl;                
                    // Will create to add  a student to the StudentDB
                    break;
                case 4:
		    std::cout << "\nAdd Instructor to Instructor Database:" << std::endl;
                    //Will Create to add Instructor to InstructorDB
                    break;
                case 5:
                    std::cout << "Exiting program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
            std::cout << std::endl;
        } while (choice != 5);
    }
    else
    {
        std::cout << "Invalid username or password. Access denied." << std::endl;
    }

    return 0;
}
