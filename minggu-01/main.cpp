#include <iostream>
#include <iterator>
#include "model/model_admin.h"
#include "view/view_admin.h"
#include "database/option.h"
#include "include/utils.h"

using namespace std;

int main() {
    DBInitAdmin();
    bool isRunning = true;

    Clear();
    Title("SISTEM ABSENSI");

    while (isRunning) {
        for (int i = 0; i < (int)size(options); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }

        switch (int choice = InputInt("Input your choice: ")) {
            case 1:
                Clear();
                VLoginAdmin();
                break;
            case 2:
                // TODO: REGISTER
                break;
            case 3:
                Clear();
                isRunning = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
    return 0;
}
