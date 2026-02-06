#ifndef MINGGU_01_MODEL_ADMIN_H
#define MINGGU_01_MODEL_ADMIN_H

#include <string>
#include "../database/db_admin.h"
#include "../include/utils.h"

using namespace std;

inline bool MLoginAdmin(const string &username, const string &password) {
    if (admins.username == username && admins.password == password) {
        Clear();
    } else {
        Clear();
        return false;
    }

    return true;
}

#endif //MINGGU_01_MODEL_ADMIN_H
