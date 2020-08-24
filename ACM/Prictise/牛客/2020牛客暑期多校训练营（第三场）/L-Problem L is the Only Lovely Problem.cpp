#include <bits/stdc++.h>
using namespace std;

string t = "lovely", s;

int main() {
	cin >> s;
	int m = t.length();
	if(s.length() < m) puts("ugly");
	else {
		for(int i = 0;i < s.length(); i++) {
			if(s[i] < 'a') s[i] += 32;
		}
		string a = "";
		for(int i = 0;i < 6; i++) a += s[i];
		if(a == t) puts("lovely");
		else puts("ugly");
	}
}