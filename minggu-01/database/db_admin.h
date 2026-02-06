#ifndef MINGGU_01_DB_ADMIN_H
#define MINGGU_01_DB_ADMIN_H

#include <string>
using namespace std;

struct Admin {
    string username;
    string password;
    string verifyPassword;
};

inline Admin admins;

inline void DBInitAdmin() {
    admins.username = "admin";
    admins.password = "admin";
};

#endif //MINGGU_01_DB_ADMIN_H
