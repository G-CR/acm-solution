#include <bits/stdc++.h>
using namespace std;

string s;

int zheng(string s) {
	int t = 0;
	for(int i = 0;i < s.length(); i++) {
		t *= 10;
		t += (s[i]-'0');
	}
	return t;
}

int fan(string s) {
	int t = 0, sta;
	for(int i = s.length()-1;i >= 0; i--) {
		if(s[i] != '0') {
			sta = i;
			break;
		}
	}
	
	for(int i = sta;i >= 0; i--) {
		t *= 10;
		t += (s[i]-'0');
	}
	return t;
}

int main() {
	cin >> s;
	printf("%d\n", zheng(s)+fan(s));
}