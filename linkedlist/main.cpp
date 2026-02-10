#include <iostream>

#include "include/helper.h"
#include "include/program.h"
#include "model/servis_model.h"
#include "storage/option_storage.h"
#include "storage/servis_storage.h"
using namespace std;

void InitServis() {
    Servis *s1 = new Servis("L 1234 AB", "Ganti Oli", 15);
    headServis = s1;
    lengthListServis++;

    Servis *s2 = new Servis("W 9988 CC", "Service Ringan", 30);
    s1->next = s2;
    lengthListServis++;

    Servis *s3 = new Servis("B 5555 XYZ", "Ganti Ban", 45);
    s2->next = s3;
    lengthListServis++;
}

int main() {
    InitServis();
    Title("SERVIS MOTOR");
    while (true) {
        PrintList(OpsiProgram, size(OpsiProgram));

        int pilihan = InputInt("Pilih opsi : ");
        cin.ignore(1000, '\n');

        switch (pilihan) {
            case 1:
                TambahAntrian();
                continue;
            case 2:
                HapusAntrian();
                continue;
            case 3:
                ListAntrian();
                Next();
                continue;
            case 4:
                TotalEstimasiServis();
                continue;
            case 5:
                PindahkanAntrianTerakhirKeDepan();
                continue;
            case 6:
                cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
                return 0;
            default:
                Clear();
                cout << "Tolong pilih opsi yang valid." << endl;
                Next();
        }
    }
}
