#include <bits/stdc++.h>
using namespace std;

int k, n;
char s[100], t[100];
int num[30], ans[200];


int main() {
	scanf("%d", &k);
	while(k--) {
		int cnt = 0;
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		scanf("%s %s", s+1, t+1);
		for(int i = 1;i <= n; i++) {
			num[s[i]-'a'+1]++;
			num[t[i]-'a'+1]++;
		}
		bool ok = 1;
		for(int i = 1;i <= 26; i++) {
			if(num[i] % 2) ok = 0;
		}
		
		if(!ok) puts("NO");
		else {
			for(int i = 1;i <= n; i++) {
				if(s[i] == t[i]) continue;
				else {
					for(int j = i+1;j <= n; j++) {
						if(s[j] == t[j]) continue;
						if(s[i] == s[j]) {
							ans[++cnt] = j; ans[++cnt] = i;
							swap(s[j], t[i]); break;
						}
						else if(s[i] == t[j]) {
							ans[++cnt] = j; ans[++cnt] = j;
							swap(s[j], t[j]);
							ans[++cnt] = j; ans[++cnt] = i;
							swap(s[j], t[i]); break;
						}
						
					}
				}
			}
			
			puts("YES");
			printf("%d\n", cnt/2);
			for(int i = 1;i <= cnt; i++) {
				printf("%d ", ans[i]);
				if(i % 2 == 0) puts("");
			}
		}
	}
}