//Author: Sekacorn
#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User();
    void setUsername(const std::string& username);
    std::string getUsername() const;
    void setPassword(const std::string& password);
    std::string getPassword() const;
    void setAccessPrivileges(bool access);
    bool hasAccessPrivileges() const;
    void encryptPassword();
    void decryptPassword();

private:
    std::string username;
    std::string password;
    bool accessPrivileges;
};

#endif  // USER_H

