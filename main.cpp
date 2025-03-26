#include <iostream>
#include <string>
#include "StudentDB.h"
#include "InstructorDB.h"
#include "User.h"

// Display main menu
void displayMenu() {
    std::cout << "========== MENU ==========" << std::endl;
    std::cout << "1. Display Student Database" << std::endl;
    std::cout << "2. Display Instructor Database" << std::endl;
    std::cout << "3. Add Student" << std::endl;
    std::cout << "4. Add Instructor" << std::endl;
    std::cout << "5. Update Student" << std::endl;
    std::cout << "6. Update Instructor" << std::endl;
    std::cout << "7. Delete Student" << std::endl;
    std::cout << "8. Delete Instructor" << std::endl;
    std::cout << "9. Find Student" << std::endl;
    std::cout << "10. Find Instructor" << std::endl;
    std::cout << "11. Exit" << std::endl;
    std::cout << "==========================" << std::endl;
}

// Utility to prompt and construct a Student object
Student createStudentFromInput() {
    std::string firstName, middleName, lastName, dob, id, email;
    std::cout << "First name: "; std::cin >> firstName;
    std::cout << "Middle name: "; std::cin >> middleName;
    std::cout << "Last name: "; std::cin >> lastName;
    std::cout << "Date of birth (YYYY-MM-DD): "; std::cin >> dob;
    std::cout << "Student ID: "; std::cin >> id;
    std::cout << "Email: "; std::cin >> email;

    return Student(firstName, middleName, lastName, dob, id, email);
}

// Utility to prompt and construct an Instructor object
Instructor createInstructorFromInput() {
    std::string firstName, middleName, lastName, email, title, summary;
    std::cout << "First name: "; std::cin >> firstName;
    std::cout << "Middle name: "; std::cin >> middleName;
    std::cout << "Last name: "; std::cin >> lastName;
    std::cout << "Email: "; std::cin >> email;
    std::cout << "Title: "; std::cin >> title;
    std::cin.ignore(); // flush newline
    std::cout << "Summary: "; std::getline(std::cin, summary);

    return Instructor(firstName, middleName, lastName, email, title, summary);
}

// Add some mock/test data to StudentDB
void seedStudentDB(StudentDB& db) {
    db.addStudent(Student("Alice", "B", "Carter", "2002-05-14", "S1001", "alice@example.com"));
    db.addStudent(Student("Bob", "D", "Evans", "2001-11-03", "S1002", "bob@example.com"));
}

// Add mock/test data to InstructorDB
void seedInstructorDB(InstructorDB& db) {
    db.addInstructor(Instructor("Dr", "James", "Hughes", "hughes@school.edu", "Physics", "Expert in quantum physics"));
    db.addInstructor(Instructor("Ms", "Linda", "Gray", "lgray@school.edu", "Math", "Loves teaching calculus"));
}

// Main app loop
int main() {
    User user;
    user.setUsername("admin");
    user.setPassword("password");
    user.setAccessPrivileges(true);

    StudentDB studentDB;
    InstructorDB instructorDB;

    // Load mock data for demo/testing
    seedStudentDB(studentDB);
    seedInstructorDB(instructorDB);

    std::string username, password;
    std::cout << "Username: "; std::cin >> username;
    std::cout << "Password: "; std::cin >> password;

    if (user.getUsername() == username && user.getPassword() == password && user.hasAccessPrivileges()) {
        int choice;
        do {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            std::string id;
            switch (choice) {
                case 1:
                    std::cout << "\n-- Student Database --\n";
                    studentDB.displayDatabase();
                    break;
                case 2:
                    std::cout << "\n-- Instructor Database --\n";
                    instructorDB.displayDatabase();
                    break;
                case 3:
                    studentDB.addStudent(createStudentFromInput());
                    std::cout << " Student added!\n";
                    break;
                case 4:
                    instructorDB.addInstructor(createInstructorFromInput());
                    std::cout << " Instructor added!\n";
                    break;
                case 5:
                    std::cout << "Enter student ID to update: ";
                    std::cin >> id;
                    studentDB.changeStudent(id, createStudentFromInput());
                    std::cout << " Student updated!\n";
                    break;
                case 6:
                    std::cout << "Enter instructor ID to update: ";
                    std::cin >> id;
                    instructorDB.changeInstructor(id, createInstructorFromInput());
                    std::cout << " Instructor updated!\n";
                    break;
                case 7:
                    std::cout << "Enter student ID to delete: ";
                    std::cin >> id;
                    studentDB.removeStudent(id);
                    std::cout << " Student removed!\n";
                    break;
                case 8:
                    std::cout << "Enter instructor ID to delete: ";
                    std::cin >> id;
                    instructorDB.removeInstructor(id);
                    std::cout << " Instructor removed!\n";
                    break;
                case 9:
                    std::cout << "Enter student ID to find: ";
                    std::cin >> id;
                    if (Student* s = studentDB.findStudent(id)) {
                        std::cout <<  Found: " << s->getFirstName() << " " << s->getLastName() << "\n";
                    } else {
                        std::cout << " Student not found.\n";
                    }
                    break;
                case 10:
                    std::cout << "Enter instructor ID to find: ";
                    std::cin >> id;
                    if (Instructor* i = instructorDB.findInstructor(id)) {
                        std::cout << " Found: " << i->getFirstName() << " " << i->getLastName() << "\n";
                    } else {
                        std::cout << " Instructor not found.\n";
                    }
                    break;
                case 11:
                    std::cout << " Exiting program..." << std::endl;
                    break;
                default:
                    std::cout << " Invalid choice. Try again." << std::endl;
                    break;
            }

            std::cout << std::endl;
        } while (choice != 11);
    } else {
        std::cout << " Access Denied.\n";
    }

    return 0;
}
