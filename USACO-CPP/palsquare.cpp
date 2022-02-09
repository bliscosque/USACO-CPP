/*
ID: bliscos1
TASK: palsquare
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 300


using namespace std;

string conv_rev(int i, int b) {
	string c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res = "";
	while (i > 0) {
		
		res += c[i % b];
		i = i / b;
	}
	return res;
}

int mainPS() {
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	int b;
	fin >> b;
	for (int i = 1; i <= 300; i++) {
		//string s1, s2;

		//_itoa(i, n1, b);
		//s1 = n1;
		//s2 = n1;
		//reverse(s1.begin(), s1.end());
		//if (s1 == s2) {
		string s1 = conv_rev(i*i,b);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
			
			if (s1 == s2) {
				//cout << i << endl;
				string s3 = conv_rev(i, b);
				reverse(s3.begin(), s3.end());
				//transform(s4.begin(), s4.end(), s4.begin(), ::toupper);
				fout << s3 << " " << s1 << endl;
			}
		//}

	}

	return 0;
}