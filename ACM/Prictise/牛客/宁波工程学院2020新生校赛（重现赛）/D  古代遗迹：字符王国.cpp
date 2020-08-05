#include <bits/stdc++.h>
using namespace std;

int _, ch[30], num[30];
string s, t;

bool check() {
	int cha = 0;
	for(int i = 1;i <= 26; i++) {
		cha += abs(num[i]-ch[i]);
	}
	if(cha <= 2) return 1;
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cin >> s >> t;
		int nt = t.length();
		memset(num, 0, sizeof(num));
		memset(ch, 0, sizeof(ch));
//		for(int i = 1;i <= 26; i++) printf("%d ", num[i]); puts("");
		int l = 0, r = nt-1, ns = s.length(), ans = 0;
		for(int i = l;i <= r; i++) num[s[i]-'a'+1]++, ch[t[i]-'a'+1]++;
		while(r < ns) {
			if(check()) ans++;
			num[s[l]-'a'+1]--;
			if(r+1 <= ns-1) num[s[r+1]-'a'+1]++;
			l++; r++;
		}
		printf("%d\n", ans);
	}
}