/*
ID: bliscos1
TASK: dualpal
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#define MAX 300


using namespace std;

string conv_rev1(int i, int b) {
	string c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res = "";
	while (i > 0) {

		res += c[i % b];
		i = i / b;
	}
	return res;
}

bool checkRule(int i) {
	int count = 0;
	for (int b = 2; b <= 10; b++) {
		string s1 = conv_rev1(i, b);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		//cout << i << " " << b << " " << s1 << " " << s2 << endl;
		if (s1 == s2) count++;
		if (count > 1) return true;
	}
	return false;
	
}

int main() {
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	int n, s;
	fin >> n;
	fin >> s;
	int count = 0;
	for (int i = s+1; i <= 100000; i++) {
		if (checkRule(i)) {
			count++;
			fout << i << endl;
			if (count == n) break;
		}
	}

	return 0;
}