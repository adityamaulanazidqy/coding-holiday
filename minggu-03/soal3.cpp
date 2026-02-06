#include <iostream>
#include <string>
#include "include/utils.h"

using namespace std;

struct Mahasiswa {
    string nama;
    float ipk;
};

void updateIPK(Mahasiswa *m) {
    if (m != nullptr) {
        m->ipk += 0.1;
    }
}

int main() {
    Mahasiswa m;
    m.nama = InputStr("Masukkan nama: ");
    do {
        m.ipk = InputFloat("Masukkan IPK: ");
        if (m.ipk > 4) {
            cout << "IPK tidak boleh lebih dari 4!" << endl;
        }
    } while (m.ipk > 4);

    updateIPK(&m);

    Line();
    cout << "IPK setelah update: " << m.ipk << endl;

    return 0;
}
