//Authour: Sekacorn
#include "InstructorDB.h"

// Constructor
InstructorDB::InstructorDB()
    : head(nullptr), tail(nullptr)
{
}

// Destructor
InstructorDB::~InstructorDB()
{
    Instructor* current = head;
    while (current) {
        Instructor* next = current->next;
        delete current;
        current = next;
    }
}

// Add an instructor to the database
void InstructorDB::addInstructor(const Instructor& instructor)
{
    Instructor* newInstructor = new Instructor(instructor);
    if (!head) {
        head = newInstructor;
        tail = newInstructor;
    } else {
        tail->next = newInstructor;
        newInstructor->prev = tail;
        tail = newInstructor;
    }
}

// Remove an instructor from the database
void InstructorDB::removeInstructor(const std::string& instructorId)
{
    Instructor* current = head;
    while (current) {
        if (current->getInstructorId() == instructorId) {
            if (current == head) {
                head = current->next;
                if (head)
                    head->prev = nullptr;
                else
                    tail = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                if (tail)
                    tail->next = nullptr;
                else
                    head = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            break;
        }
        current = current->next;
    }
}

// Change the fields of an instructor in the database
void InstructorDB::changeInstructor(const std::string& instructorId, const Instructor& newInstructor)
{
    Instructor* current = head;
    while (current) {
        if (current->getInstructorId() == instructorId) {
            *current = newInstructor;
            break;
        }
        current = current->next;
    }
}

//Find Instructor
Instructor* InstructorDB::findInstructor(const std::string& instructorId) const
{
    Instructor* current = head;
    while (current) {
        if (current->getInstructorId() == instructorId)
            return current;
        current = current->next;
    }
    return nullptr;
}


// Display the database
void InstructorDB::displayDatabase() const
{
    Instructor* current = head;
    while (current) {
        // Display instructor information
        current = current->next;
    }
}

