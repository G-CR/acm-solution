#include <bits/stdc++.h>
using namespace std;

int T, n;
char a[100005], b[100005];
char t1[100005], t2[100005];
int num[30];
int main() {
	scanf("%d", &T);
	while(T--) {
		memset(num, 0, sizeof(num));
		int cnt = 0; bool ok0 = 1,ok1 = 1, ok2 = 1;
		scanf("%d", &n);
		scanf("%s %s", a+1, b+1);
		for(int i = 1;i <= n; i++) {
			if(a[i] != b[i]) {
				t1[++cnt] = a[i];
				t2[cnt] = b[i];
				num[a[i]-'a'+1]++;
				num[b[i]-'a'+1]++;
			}
		}
		for(int i = 1;i <= 26; i++) if(num[i] % 2) {ok0 = 0; break;}
		if(!ok0) {puts("NO"); continue;}
		
		for(int i = 1;i <= cnt; i++) {
			if(i == cnt) {
				if(t1[i] != t2[1]) {
					ok1 = 0; break;
				}
				continue;
			}
			if(t1[i] != t2[i+1]) {
				ok1 = 0; break;
			}
		}
		
		for(int i = 1;i <= cnt; i++) {
			if(i == 1) {
				if(t1[i] != t2[cnt]) {
					ok2 = 0; break;
				}
				continue;
			}
			if(t1[i] != t2[i-1]) {
				ok2 = 0; break;
			}
		}
		if(ok1 || ok2) puts("YES");
		else puts("NO");
	}
}