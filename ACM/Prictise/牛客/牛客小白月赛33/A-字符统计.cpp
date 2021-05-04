#include <bits/stdc++.h>
using namespace std;

int _;
string s, t;

int main() {
	scanf("%d", &_);
	int line = 0, dc = 0, zf = 0; getchar();
	while(getline(cin, t)) {
		int l = 0, r = t.length()-1;
		if(t[r] == ' ') r--;
		if(t[l] == ' ') l++;
		s = "";
		for(int i = l; i <= r; i++) s += t[i];
		if(s == "=====") {
			printf("%d %d %d\n", line, dc, zf);
			line = 0, dc = 0, zf = 0;
			continue;
		}
		line++; zf += t.length();
		int pos = 0;
		
		while(pos < s.length()) {
			if(s[pos] == ' ') {
				dc++;
				while(s[pos] == ' ') pos++;
			}
			pos++;
		}
		
		if(s.length()) dc++;
	}
	printf("%d %d %d\n", line, dc, zf);
}