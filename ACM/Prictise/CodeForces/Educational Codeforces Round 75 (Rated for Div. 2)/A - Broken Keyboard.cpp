#include <bits/stdc++.h>
using namespace std;

int t;
char s[505], ans[30];
bool ok[500];

int find(int p) {
	int n = strlen(s+1);
	int num = 1;
	if(p == n) return 1;
	for(int i = p+1;i <= n; i++) {
		if(s[i] == s[i-1]) num++;
		else break;
	}
	return num;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s+1);
		int n = strlen(s+1);
		memset(ok, 0, sizeof(ok));
		int cnt = 0, num;
		for(int i = 1;i <= n;) {
			num = find(i);
			if(!ok[s[i]-'0']) {
				if(num % 2 != 0) {
					ans[++cnt] = s[i];
					ok[s[i]-'0'] = 1;
				}
			}
			i += num;
		}
		sort(ans+1, ans+1+cnt);
		for(int i = 1;i <= cnt; i++) printf("%c", ans[i]);
		puts("");
	}
}