#include "contact.h"

// Constructor
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email, const std::string& group)
    : name(name), phone(phone), email(email), group(group) {}

// Getters
std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhone() const {
    return phone;
}

std::string Contact::getEmail() const {
    return email;
}

std::string Contact::getGroup() const {
    return group;
}

// Display contact info
void Contact::display() const {
    std::cout << "Name: " << name << "\nPhone: " << phone
              << "\nEmail: " << email << "\nGroup: " << group << "\n";
}
