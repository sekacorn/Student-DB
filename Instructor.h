//Authour: Sekacorn
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>

class Instructor {
private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string emailAddress;
    std::string title;
    std::string summary;

public:
    // Constructors
    Instructor();
    Instructor(const std::string& firstName, const std::string& middleName, const std::string& lastName,
        const std::string& emailAddress, const std::string& title, const std::string& summary);

    // Getters
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    std::string getTitle() const;
    std::string getSummary() const;

    // Setters
    void setFirstName(const std::string& firstName);
    void setMiddleName(const std::string& middleName);
    void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& emailAddress);
    void setTitle(const std::string& title);
    void setSummary(const std::string& summary);
};

#endif
