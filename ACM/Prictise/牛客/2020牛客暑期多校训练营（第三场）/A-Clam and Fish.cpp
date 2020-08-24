#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s;
		int ans = 0, nothing = 0, haver = 0;
		for(int i = 0;i < n; i++) {
			if(s[i]-'0' >= 2) ans++;
			if(s[i] == '0') nothing++;
		}
		
		for(int i = 0;i < n; i++) {
			if(s[i] == '0') {
				if(haver) haver--, ans++;
				nothing--;
			}
			else if(s[i] == '1') {
				if(haver > nothing) {
					haver--;
					ans++;
				}
				else {
					haver++;
				}
			}
		}
		
		printf("%d\n", ans);
	}
}