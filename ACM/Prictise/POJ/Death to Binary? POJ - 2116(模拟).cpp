#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long fac[55];
string s1, s2;
long long res;

string solve(string s) {
	int pos = -1;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] != '0') {
			pos = i; break;
		}
	}
	if(pos == -1) return "0";
	
	string t = "";
	for(int i = pos;i < s.length(); i++) t += s[i];
	s = t;
	if(s.length() > 0) {
		reverse(s.begin(), s.end());
		long long a = 0;
		for(int i = 0;i < s.length(); i++) {
			if(s[i] == '1') a += fac[i];
		} s = "";
		res += a;
		for(int i = 54;i >= 0; i--) {
			if(a >= fac[i]) {
				s += '1';
				a -= fac[i];
			}
			else if(s.length() > 0){
				s += '0';
			}
		}
	}
	return s;
}

int main() {
	fac[0] = 1; fac[1] = 2;
	for(int i = 2;i < 55; i++) {
		fac[i] = fac[i-1] + fac[i-2];
//		cout << fac[i] << endl;
	}
	
	while(cin >> s1 >> s2) {
		res = 0;
		s1 = solve(s1);
		s2 = solve(s2);
		string fin = "";
		if(res) {
			for(int i = 54;i >= 0; i--) {
				if(res >= fac[i]) {
					fin += '1';
					res -= fac[i];
				}
				else if(fin.length() > 0){
					fin += '0';
				}
			}
		}
		else fin = "0";
		
		int len = fin.length()+2;
		reverse(s1.begin(), s1.end()); while(s1.length() < len) s1 += ' ';
		reverse(s2.begin(), s2.end()); while(s2.length() < len-1) s2 += ' ';
		reverse(fin.begin(), fin.end()); while(fin.length() < len) fin += ' ';
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		reverse(fin.begin(), fin.end());
		
		cout << s1 << endl;
		cout << "+" << s2 << endl;
		cout << "  ";
		for(int i = 1;i <= len-2; i++) cout << "-"; puts("");
		cout << fin << "\n" << "\n";
	}
}