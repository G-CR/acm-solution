#include <bits/stdc++.h>
using namespace std;

int _, t[30], now[30];
string s;
string k = "puleyaknoi";

bool check() {
	for(char i: k) {
		if(now[i-'a'] < t[i-'a']) return 0;
	}
	return 1;
}

int main() {
	for(char i: k) t[i-'a'] = 1;
	scanf("%d", &_);
	while(_--) {
		memset(now, 0, sizeof now);
		cin >> s;
		int l = 0, r = 0, ans = 1e9;
		while(r < s.length()) {
			now[s[r]-'a']++;
			while(check()){
				ans = min(ans, r-l+1);
				now[s[l++]-'a']--;
			}
			r++;
		}
		printf("%d\n", ans==1e9?-1:ans);
	}
}