//Authour: Sekacorn
#include "User.h"

User::User()
{
    accessPrivileges = false;
}

void User::setUsername(const std::string& username)
{
    this->username = username;
}

std::string User::getUsername() const
{
    return username;
}

void User::setPassword(const std::string& password)
{
    this->password = password;
}

std::string User::getPassword() const
{
    return password;
}

void User::setAccessPrivileges(bool access)
{
    accessPrivileges = access;
}

bool User::hasAccessPrivileges() const
{
    return accessPrivileges;
}

void User::encryptPassword()
{
    //Will create Simple Encryption later
}

void User::decryptPassword()
{
    //Will create simple Decryption later
}
