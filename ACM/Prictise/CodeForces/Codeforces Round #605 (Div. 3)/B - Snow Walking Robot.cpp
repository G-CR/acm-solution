#include <bits/stdc++.h>
using namespace std;

int q;
string s;

int main() {
	cin >> q;
	while(q--) {
		int u = 0, d = 0, l = 0, r = 0;
		cin >> s;
		int n = s.length();
		for(int i = 0;i < n; i++) {
			if(s[i] == 'L') l++;
			if(s[i] == 'R') r++;
			if(s[i] == 'U') u++;
			if(s[i] == 'D') d++;
		}
		
		l = min(l,r); r = min(l,r);
		u = min(u,d); d = min(u,d);
		
		if(l == 0 && u == 0) {
			puts("0");
			continue;
		}
		
		if(l == 0) {
			puts("2\nUD");
			continue;
		}
		
		if(u == 0) {
			puts("2\nLR");
			continue;
		}
		
		printf("%d\n", u+d+l+r);
		while(u--) printf("U");
		while(r--) printf("R");
		while(d--) printf("D");
		while(l--) printf("L");
		puts("");
	}
}