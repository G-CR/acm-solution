#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	for(int i = 0;i < s.length(); i++) {
		if(s[i] == '5') printf("*");
		else printf("%c", s[i]);
	} puts("");
}