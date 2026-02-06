#ifndef MINGGU_01_VIEW_ADMIN_H
#define MINGGU_01_VIEW_ADMIN_H

#include "../include/utils.h"
#include "../database/db_admin.h"
#include "../model/model_admin.h"

using namespace std;

inline void VLoginAdmin() {
    Title("LOGIN ADMIN");

    bool isRunning = true;
    int countFailed = 0;

    while (isRunning) {
        Line();
        string inputUsername = InputStr("Username: ");
        string inputPassword = InputStr("Password: ");
        Line();

        bool isLoginSuccess = MLoginAdmin(inputUsername, inputPassword);
        if (!isLoginSuccess) {
            countFailed++;
            cout << "Login failed" << endl;
            if (countFailed >= 3) {
                Clear();
                cout << "You have been banned" << endl;
                Line();
                isRunning = false;
            }
        } else {
            cout << "Login success" << endl;
            isRunning = false;
        }
    }

    Pause();
}

#endif //MINGGU_01_VIEW_ADMIN_H
