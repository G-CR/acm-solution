#include <bits/stdc++.h>
using namespace std;

int n;
char s1[200005], s2[200005];
int ans1[200005], ans2[200005];

int main() {
	scanf("%d", &n);
	scanf("%s %s", s1+1, s2+1);
	int numa = 0, numb = 0;
	for(int i = 1;i <= n; i++) {
		if(s1[i] == 'a') numa++; if(s2[i] == 'a') numa++;
		if(s1[i] == 'b') numb++; if(s2[i] == 'b') numb++;
	}
	if(numa % 2 && numb % 2) return puts("-1"), 0;
	
	char t1, t2;
	int ans = 0, cnt = 0;
	for(int i = 1;i <= n; i++) {
		if(s1[i] != s2[i]) {
			for(int j = i+1;j <= n; j++) {
				if(s1[i] == s1[j] && s2[i] == s2[j]) {
					ans++;
					ans1[++cnt] = i; ans2[cnt] = j;
					char t = s1[i]; s1[i] = s2[j]; s2[j] = t;
					break;
				}
			}
		}
	}
	
	for(int i = 1;i <= n; i++) {
		if(s1[i] != s2[i]) {
			for(int j = i+1;j <= n; j++) {
				if(s1[i] == s2[j] && s2[i] == s1[j]) {
					ans += 2;
					ans1[++cnt] = j; ans2[cnt] = j;
					ans1[++cnt] = i; ans2[cnt] = j;
				}
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 1;i <= cnt; i++) {
		printf("%d %d\n", ans1[i], ans2[i]);
	}
}