#include <bits/stdc++.h>
using namespace std;

int b;

string change(int a) {
	string s = "";
	while(a) {
		int now = a % b;
		char k;
		if(now < 10) k = now + '0';
		else k = now-10+'A';
		s += k;
		a /= b;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool check(string s) {
	int l = 0, r = s.length()-1;
	while(l < r) {
		if(s[l] != s[r]) return 0;
		l++; r--;
	}
	return 1;
}

int main() {
	scanf("%d", &b);
	for(int i = 1;i <= 300; i++) {
		string me = change(i);
		string chan = change(i*i);
		if(check(chan)) {
			cout << me << " " << chan << endl;
		}
	}
}