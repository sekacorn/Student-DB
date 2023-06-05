//Authour: Sekacorn
#include "StudentDB.h"

// Constructor
StudentDB::StudentDB()
    : head(nullptr), tail(nullptr)
{
}

// Destructor
StudentDB::~StudentDB()
{
    Student* current = head;
    while (current) {
        Student* next = current->next;
        delete current;
        current = next;
    }
}

// Add a student to the database
void StudentDB::addStudent(const Student& student)
{
    Student* newStudent = new Student(student);
    if (!head) {
        head = newStudent;
        tail = newStudent;
    } else {
        tail->next = newStudent;
        newStudent->prev = tail;
        tail = newStudent;
    }
}

// Remove a student from the database
void StudentDB::removeStudent(const std::string& studentId)
{
    Student* current = head;
    while (current) {
        if (current->getStudentId() == studentId) {
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

// Change the fields of a student in the database
void StudentDB::changeStudent(const std::string& studentId, const Student& newStudent)
{
    Student* current = head;
    while (current) {
        if (current->getStudentId() == studentId) {
            *current = newStudent;
            break;
        }
        current = current->next;
    }
}

// Display the database
void StudentDB::displayDatabase() const
{
    Student* current = head;
    while (current) {
        // Display student information
        current = current->next;
    }
}
