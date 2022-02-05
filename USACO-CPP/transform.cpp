/*
ID: bliscos1
TASK: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char v90[10][10]{};
char v180[10][10]{};
char v270[10][10]{};
char vref[10][10]{};
char vr90[10][10]{};
char vr180[10][10]{};
char vr270[10][10]{};


void print(char vOrig[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << vOrig[i][j];
        }
        cout << endl;
    }
}

void rotate_90(char vOrig[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v90[i][j] = vOrig[n - j - 1][i];
        }
    }
    //print(v90);
}

void rotate_180(char vOrig[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v180[i][j] = vOrig[n - j - 1][i];
        }
    }
    //print(v90);
}

void rotate_270(char vOrig[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v270[i][j] = vOrig[n - j - 1][i];
        }
    }
    //print(v90);
}




//both are equals?
bool test_6(char vOrig[10][10], char vTrans[10][10]) {
    //print(vOrig);
    //print(vTrans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vOrig[i][j] != vTrans[i][j]) return false;
        }
    }
    return true;
}

//rotate 90
bool test_1(char vOrig[10][10], char vTrans[10][10]) {
    rotate_90(vOrig);
    //print(v90);
    //print(vTrans);
    return test_6(v90, vTrans);
}

bool test_2(char vOrig[10][10], char vTrans[10][10]) {
    rotate_180(v90);
    return test_6(v180, vTrans);
}

bool test_3(char vOrig[10][10], char vTrans[10][10]) {
    rotate_270(v180);
    return test_6(v270, vTrans);
}

bool test_4(char vOrig[10][10], char vTrans[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            vref[i][j] = vOrig[i][n - j];
        }
    }
    return test_6(vref, vTrans);
}

bool test_5(char vOrig[10][10], char vTrans[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vr90[i][j] = vref[n - j - 1][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vr180[i][j] = vr90[n - j - 1][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vr270[i][j] = vr180[n - j - 1][i];
        }
    }
    if (test_6(vr90, vTrans) || test_6(vr180, vTrans) || test_6(vr270, vTrans)) return true;
    return false;
}

int mainT() {
    ofstream fout("transform.out");
    ifstream fin("transform.in"); //for the current file, answer should be 5
    
    char vOrig[10][10]{}, vDest[10][10]{};

    fin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        fin >> line;
        for (int j = 0; j < n; j++) {
            vOrig[i][j] = line[j];
        }
    }
    for (int i = 0; i < n; i++) {
        string line;
        fin >> line;
        for (int j = 0; j < n; j++) {
            vDest[i][j] = line[j];
        }
    }
    if (test_1(vOrig, vDest)) fout << "1" << endl;
    else if (test_2(vOrig, vDest)) fout << "2" << endl;
    else if (test_3(vOrig, vDest)) fout << "3" << endl;
    else if (test_4(vOrig, vDest)) fout << "4" << endl;
    else if (test_5(vOrig, vDest)) fout << "5" << endl;
    else if (test_6(vOrig, vDest)) fout << "6" << endl;
    else fout << "7" << endl;

    return 0;
}