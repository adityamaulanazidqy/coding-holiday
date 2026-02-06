#include <iostream>
#include <string>
#include "include/utils.h"

using namespace std;

struct Mahasiswa {
    string nama;
    float ipk;
};

int main() {
    int n = InputInt("Masukkan jumlah mahasiswa: ");
    cin.ignore();

    Mahasiswa m[n];
    for (int i = 0; i < n; i++) {
        Title("Mahasiswa ke-" + to_string(i + 1));
        m[i].nama = InputStr("Masukkan nama: ");
        
        do {
            m[i].ipk = InputFloat("Masukkan IPK: ");
            if (m[i].ipk > 4) {
                cout << "IPK tidak boleh lebih dari 4!" << endl;
            }
        } while (m[i].ipk > 4);
        
        cin.ignore();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            Mahasiswa* p1 = &m[j];
            Mahasiswa* p2 = &m[j+1];
            
            if (p1->ipk < p2->ipk) {
                Mahasiswa temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }

    Clear();
    Title("HASIL SORTING IPK (DESCENDING)");
    for (int i = 0; i < n; i++) {
        cout << m[i].nama << " " << m[i].ipk << endl;
    }
    Line();

    return 0;
}
