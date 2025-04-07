#ifndef DATABASE_H
#define DATABASE_H
#include "contact.h"
#include <vector>
class Database {
public:
    static void initialize();
    static void saveContacts(const std::vector<Contact>&);
    static std::vector<Contact> loadContacts();
    static void close();
};
#endif