#include <iostream>
#include <ostream>
#include <string>
#include "../include/utils.h"
using namespace std;

string InputStr(const string &title) {
    string n;
    cout << title;
    getline(cin, n);
    return n;
}

int InputInt(const string &title) {
    int val;
    cout << title;
    while (!(cin >> val)) {
        cout << "Pake angka, Bos!: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return val;
}

float InputFloat(const string &title) {
    float val;
    cout << title;
    while (!(cin >> val)) {
        cout << "Pake nilai floating point!: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return val;
}

void Line() {
    cout << string(32, '-') << endl;
}

void Title(const string &title) {
    cout << string(8, '-') << " " << title << " " << string(8, '-') << endl;
}

void Clear() {
    system("cls || clear");
}