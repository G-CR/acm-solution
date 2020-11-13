#include <bits/stdc++.h>
using namespace std;

string s;
char yy[] = {'a', 'e', 'i', 'o', 'u', 'y'};

char rev(char a) {
	for(int i = 5;i >= 0; i--) {
		if(yy[i] <= a) return yy[i];
	}
}

int main() {
	while(cin >> s) {
		for(int i = 0;i < s.length(); i++) {
			printf("%c", rev(s[i]));
		}
		puts("");
	}
}