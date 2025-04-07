#include "ui.h"
#include <iostream>
#include <thread>
void UI::run(Phonebook& pb) {
    int choice;
    do {
        std::cout << "\n==== Phonebook Menu ===="
                  << "\n1. Add Contact\n2. Show Contacts\n3. Search Contact\n4. Sort Contacts\n5. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            std::string n, p, e, g;
            std::cout << "Name: "; getline(std::cin, n);
            std::cout << "Phone: "; getline(std::cin, p);
            std::cout << "Email: "; getline(std::cin, e);
            std::cout << "Group: "; getline(std::cin, g);
            pb.add(Contact(n, p, e, g));
        } else if (choice == 2) {
            pb.showAll();
        } else if (choice == 3) {
            std::string key;
            std::cout << "Search Name: "; getline(std::cin, key);
            std::thread t([&](){ pb.search(key); });
            t.join();
        } else if (choice == 4) {
            int opt;
            std::cout << "1. Name\n2. Phone\n3. Email\nSort by: ";
            std::cin >> opt; std::cin.ignore();
            pb.sortBy(opt);
        }
    } while (choice != 5);
}
