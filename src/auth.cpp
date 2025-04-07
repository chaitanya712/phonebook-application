#include "auth.h"
#include <iostream>
bool Auth::login() {
    std::string pass;
    std::cout << "Enter password: ";
    std::cin >> pass;
    return pass == "admin";
}