//Authour: Sekacorn
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string dateOfBirth;
    std::string studentId;
    std::string emailAddress;

public:
    // Constructors
    Student();
    Student(const std::string& firstName, const std::string& middleName, const std::string& lastName,
        const std::string& dateOfBirth, const std::string& studentId, const std::string& emailAddress);

    // Getters
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    std::string getDateOfBirth() const;
    std::string getStudentId() const;
    std::string getEmailAddress() const;

    // Setters
    void setFirstName(const std::string& firstName);
    void setMiddleName(const std::string& middleName);
    void setLastName(const std::string& lastName);
    void setDateOfBirth(const std::string& dateOfBirth);
    void setStudentId(const std::string& studentId);
    void setEmailAddress(const std::string& emailAddress);
};

#endif
