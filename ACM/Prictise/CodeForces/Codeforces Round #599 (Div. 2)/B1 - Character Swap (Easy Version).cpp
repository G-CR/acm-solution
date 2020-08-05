#include <bits/stdc++.h>
using namespace std;

int k, n;
char s[10004], t[10004];
int ans[10];

int main() {
	scanf("%d", &k);
	while(k--) {
		scanf("%d", &n);
		scanf("%s %s", s+1, t+1);
		bool ok = 1;
		for(int i = 1;i <= n; i++) {
			if(s[i] != t[i]) {
				ok = 0; break;
			}
		}
		if(ok) puts("YES");
		else {
			int cnt = 0; ok = 1;
			for(int i = 1;i <= n; i++) {
				if(cnt > 2) {
					ok = 0; break;
				}
				if(s[i] != t[i]) {
					ans[++cnt] = i;
				}
			}
			if(!ok) {
				puts("NO");
				continue;
			}
			
			if(cnt == 1) ok = 0;
			else {
				if(s[ans[1]] == s[ans[2]] && t[ans[1]] == t[ans[2]]) {
					ok = 1;
				}
				else {
					ok = 0;
				}
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
}