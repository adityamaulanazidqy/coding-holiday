//
// Created by zidqy on 2/10/26.
//

#include <iostream>
#include "../include/helper.h"

using namespace std;

string InputStr(string str) {
    cout << str;
    string input;
    getline(cin, input);
    return input;
}

int InputInt(string str) {
    int input;
    while (true) {
        cout << str;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Tolong masukkan angka." << endl;
        } else break;
    }
    return input;
}

void Title(string title) {
    cout << string(8, '=') << " " << title << " " << string(8, '=') << endl;
}

void Line() {
    cout << string(24, '-') << endl;
}

void Clear() {
    system("clear || cls");
}

void PrintList(string list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i + 1 << "] " << list[i] << endl;
    }
}

void Next() {
    cout << "Press enter to continue..." << endl;
    getchar();
}
