#include "database.h"
extern "C" {
  #include "sqlite3.h"
}
#include <iostream>
static sqlite3* db;
void Database::initialize() {
    if (sqlite3_open("contacts.db", &db)) {
        std::cerr << "Can't open database\n";
    }
    const char* sql = "CREATE TABLE IF NOT EXISTS contacts(name TEXT, phone TEXT, email TEXT, group_name TEXT);";
    char* err;
    sqlite3_exec(db, sql, 0, 0, &err);
}
void Database::saveContacts(const std::vector<Contact>& list) {
    sqlite3_exec(db, "DELETE FROM contacts;", 0, 0, 0);
    for (auto& c : list) {
        std::string sql = "INSERT INTO contacts VALUES('" + c.getName() + "','" + c.getPhone() + "','" + c.getEmail() + "','" + c.getGroup() + "');";
        sqlite3_exec(db, sql.c_str(), 0, 0, 0);
    }
}
std::vector<Contact> Database::loadContacts() {
    std::vector<Contact> contacts;
    const char* sql = "SELECT * FROM contacts;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string name = (const char*)sqlite3_column_text(stmt, 0);
            std::string phone = (const char*)sqlite3_column_text(stmt, 1);
            std::string email = (const char*)sqlite3_column_text(stmt, 2);
            std::string group = (const char*)sqlite3_column_text(stmt, 3);
            contacts.emplace_back(name, phone, email, group);
        }
    }
    sqlite3_finalize(stmt);
    return contacts;
}
void Database::close() {
    sqlite3_close(db);
}
