#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "bst.h"
#include <vector>
#include <string>
class Phonebook {
public:
    void add(Contact);
    void showAll();
    void search(const std::string&);
    void sortBy(int);
    void loadFromDatabase();
    void saveToDatabase();
private:
    BST bst;
    std::vector<Contact> list;
};
#endif