// =============================
// Includes: BST, Sorting, SQLite DBMS, File Handling, Multithreading

// main.cpp
#include "auth.h"
#include "phonebook.h"
#include "ui.h"
#include "database.h"
#include <iostream>


int main() {
    
    std::cout << "Starting VPhonebook...\n";
    if (!Auth::login()) {
        std::cout << "Access denied.\n";
        return 0;
    }
     std::cout << "Logged in successfully!\n";
        Database::initialize();
    Phonebook pb;
    pb.loadFromDatabase();

    UI::run(pb);

    pb.saveToDatabase();
    Database::close();

    // return 0;
    
    std::cin.get();
}
