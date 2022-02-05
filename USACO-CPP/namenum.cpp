/*
ID: bliscos1
TASK: namenum
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string conv(string s) {
	string ret = "";
	for (char c: s) {
		if (c >= 'A' && c <= 'C') ret += '2';
		else if (c >= 'D' && c <= 'F') ret += '3';
		else if (c >= 'G' && c <= 'I') ret += '4';
		else if (c >= 'J' && c <= 'L') ret += '5';
		else if (c >= 'M' && c <= 'O') ret += '6';
		else if (c >= 'P' && c <= 'S') ret += '7';
		else if (c >= 'T' && c <= 'V') ret += '8';
		else if (c >= 'W' && c <= 'Y') ret += '9';
	}
	return ret;
}

int main() {

	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream dic("dict.txt");

	multimap<string, string> mm;
	
	string lDic;
	while (dic >> lDic) {
		mm.insert({ conv(lDic), lDic });
	}
	
	string inp;
	fin >> inp;

	vector<string> res;
	auto it1 = mm.equal_range(inp);
	

	for (auto it = it1.first; it != it1.second; it++) {
		//cout << it->first << " " << it->second << endl;
		res.push_back(it->second);
	}
	sort(res.begin(), res.end());
	for (string s : res) {
		fout << s << endl;
	}
	if (res.size() == 0) fout << "NONE" << endl;
	
	return 0;
}