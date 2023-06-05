//Authour: Sekacorn
#include "Student.h"

// Constructors
Student::Student()
{
}

Student::Student(const std::string& firstName, const std::string& middleName, const std::string& lastName,
    const std::string& dateOfBirth, const std::string& studentId, const std::string& emailAddress)
    : firstName(firstName), middleName(middleName), lastName(lastName), dateOfBirth(dateOfBirth),
    studentId(studentId), emailAddress(emailAddress)
{
}

// Getters
std::string Student::getFirstName() const
{
    return firstName;
}

std::string Student::getMiddleName() const
{
    return middleName;
}

std::string Student::getLastName() const
{
    return lastName;
}

std::string Student::getDateOfBirth() const
{
    return dateOfBirth;
}

std::string Student::getStudentId() const
{
    return studentId;
}

std::string Student::getEmailAddress() const
{
    return emailAddress;
}

// Setters
void Student::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Student::setMiddleName(const std::string& middleName)
{
    this->middleName = middleName;
}

void Student::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Student::setDateOfBirth(const std::string& dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Student::setStudentId(const std::string& studentId)
{
    this->studentId = studentId;
}

void Student::setEmailAddress(const std::string& emailAddress)
{
    this->emailAddress = emailAddress;
}
