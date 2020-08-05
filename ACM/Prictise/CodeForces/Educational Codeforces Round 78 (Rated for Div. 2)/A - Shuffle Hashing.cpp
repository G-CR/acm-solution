#include <bits/stdc++.h>
using namespace std;

char p[105], h[105];
int T;
int nump[30], numt[30];

int main() {
	scanf("%d", &T);
	while(T--) {
		bool ok;
		scanf("%s %s", p+1, h+1);
		int n = strlen(p+1);
		int m = strlen(h+1);
		memset(nump, 0, sizeof(nump));
		memset(numt, 0, sizeof(numt));
		for(int i = 1;i <= n; i++) {
			nump[p[i]-'a'+1]++;
		}
		for(int i = 1;i <= m; i++) {
			ok = 1;
			for(int j = i;j <= min(i+n-1, m); j++) {
				numt[h[j]-'a'+1]++;
			}
			
			for(int j = 1;j <= 26; j++) {
				if(nump[j] != numt[j]) {
					ok = 0;
					break;
				}
			}
			
			if(ok) {
//				for(int j = 1;j <= n; j++) printf("%d", nump[j]);puts("");
//				for(int j = 1;j <= n; j++) printf("%d", numt[j]);puts("");
				puts("YES");
				break;
			}
			else {
				for(int j = 1;j <= 26; j++) numt[j] = 0;
			}
		}
		if(!ok)puts("NO");
	}
}