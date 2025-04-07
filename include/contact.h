#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;
    std::string group;

public:
    Contact() = default;
    Contact(const std::string& name, const std::string& phone, const std::string& email, const std::string& group);

    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getGroup() const;

    void display() const;
};

#endif
