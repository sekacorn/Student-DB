//Authour: Sekacorn
#ifndef STUDENTDB_H
#define STUDENTDB_H

#include "Student.h"

class StudentDB {
private:
    Student* head;
    Student* tail;

public:
    // Constructor
    StudentDB();

    // Destructor
    ~StudentDB();

    // Add a student to the database
    void addStudent(const Student& student);

    // Remove a student from the database
    void removeStudent(const std::string& studentId);

    // Change the fields of a student in the database
    void changeStudent(const std::string& studentId, const Student& newStudent);

    // Display the database
    void displayDatabase() const;
};

#endif
