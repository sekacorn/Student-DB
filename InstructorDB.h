//Author: Sekacorn
#ifndef INSTRUCTORDB_H
#define INSTRUCTORDB_H

#include "Instructor.h"

class InstructorDB {
private:
    Instructor* head;
    Instructor* tail;

public:
    // Constructor
    InstructorDB();

    // Destructor
    ~InstructorDB();

    // Add an instructor to the database
    void addInstructor(const Instructor& instructor);

    // Remove an instructor from the database
    void removeInstructor(const std::string& instructorId);

    // Change the fields of an instructor in the database
    void changeInstructor(const std::string& instructorId, const Instructor& newInstructor);

    // Display the database
    void displayDatabase() const;
};

#endif

