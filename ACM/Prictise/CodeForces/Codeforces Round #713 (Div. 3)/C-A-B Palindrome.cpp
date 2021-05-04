#include <bits/stdc++.h>
using namespace std;

int _, a, b;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &a, &b); // 0 1
		cin >> s;
		int n = s.length();
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') a--;
			else if(s[i] == '1') b--;
		}
		for(int i = 0; i < n; i++) {
			int j = n-i-1;
			if(s[i] == '?' && s[j] != '?') {
				s[i] = s[j];
				if(s[j] == '0') a--;
				else b--;
			}
			else if(s[i] != '?' && s[j] == '?') {
				s[j] = s[i];
				if(s[i] == '0') a--;
				else b--;
			}
		}
		
//		printf("a = %d b = %d\n", a, b);
//		cout << s << endl;
		
		int l = 0, r = n-1;
		bool ok = 1;
		while(l <= r) {
			if(s[l] != '?' && s[r] != '?' && s[l] != s[r]) {
				ok = 0;
				break;
			}
			if(l == r && s[l] == '?') {
				if(a) {
					s[l] = '0';
					a--;
				}
				else {
					s[r] = '1';
					b--;
				}
			}
			if(s[l] == '?' && s[r] == '?') {
				if(a >= b) {
					s[l] = s[r] = '0';
					a -= 2;
				}
				else {
					s[l] = s[r] = '1';
					b -= 2;
				}
			}
			l++; r--;
		}
		
//		printf("a = %d b = %d\n", a, b);
		
		if((a != 0 || b != 0) || !ok) {
			puts("-1");
		}
		else 
			cout << s << "\n";
	}
}