#include <bits/stdc++.h>
using namespace std;

string s, t;

bool check() {
	for(int i = 0, j = t.length()-1; i < j; i++, j--) {
		if(t[i] != t[j]) return 0;
	}
	return 1;
}

int main() {
	cin >> s;
	int pos = s.length()-1;
	for(int i = pos; i >= 0; i--) {
		if(s[i] != '0') {
			pos = i;
			break;
		}
	}
	for(int i = 0; i <= pos; i++) t += s[i];
	
	if(check()) puts("Yes");
	else puts("No");
}