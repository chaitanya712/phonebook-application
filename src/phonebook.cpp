#include "phonebook.h"
#include "database.h"
#include <iostream>
#include <algorithm>

void Phonebook::add(Contact c) {
    list.push_back(c);
    bst.insert(c);
}
void Phonebook::showAll() {
    bst.inorder();
}
void Phonebook::search(const std::string& name) {
    Contact* res = bst.search(name);
    if (res) std::cout << "Found: " << res->getName() << " | " << res->getPhone() << " | " << res->getEmail() << "\n";
    else std::cout << "Not found.\n";
}
void Phonebook::sortBy(int opt) {
    if (opt == 1)
        std::sort(list.begin(), list.end(), [](Contact a, Contact b) { return a.getName() < b.getName(); });
    else if (opt == 2)
        std::sort(list.begin(), list.end(), [](Contact a, Contact b) { return a.getPhone() < b.getPhone(); });
    else if (opt == 3)
        std::sort(list.begin(), list.end(), [](Contact a, Contact b) { return a.getEmail() < b.getEmail(); });
    for (auto c : list)
        std::cout << c.getName() << " | " << c.getPhone() << " | " << c.getEmail() << "\n";
}
void Phonebook::loadFromDatabase() {
    list = Database::loadContacts();
    for (auto c : list) bst.insert(c);
}
void Phonebook::saveToDatabase() {
    Database::saveContacts(list);
}