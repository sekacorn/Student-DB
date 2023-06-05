//Authour: Sekacorn
#include "Instructor.h"

// Constructors
Instructor::Instructor()
{
}

Instructor::Instructor(const std::string& firstName, const std::string& middleName, const std::string& lastName,
    const std::string& emailAddress, const std::string& title, const std::string& summary)
    : firstName(firstName), middleName(middleName), lastName(lastName), emailAddress(emailAddress),
    title(title), summary(summary)
{
}

// Getters
std::string Instructor::getFirstName() const
{
    return firstName;
}

std::string Instructor::getMiddleName() const
{
    return middleName;
}

std::string Instructor::getLastName() const
{
    return lastName;
}

std::string Instructor::getEmailAddress() const
{
    return emailAddress;
}

std::string Instructor::getTitle() const
{
    return title;
}

std::string Instructor::getSummary() const
{
    return summary;
}

// Setters
void Instructor::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Instructor::setMiddleName(const std::string& middleName)
{
    this->middleName = middleName;
}

void Instructor::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Instructor::setEmailAddress(const std::string& emailAddress)
{
    this->emailAddress = emailAddress;
}

void Instructor::setTitle(const std::string& title)
{
    this->title = title;
}

void Instructor::setSummary(const std::string& summary)
{
    this->summary = summary;
}
