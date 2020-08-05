#include <bits/stdc++.h>
using namespace std;

int n,m,a[305],l[305],r[305],t[305],minn,ans = -10000000,fin0[305],fin[305],cnt;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	
	for(int i = 1;i <= n; i++) {
		memset(fin0,0,sizeof(fin0));
		for(int k = 1;k <= n; k++) t[k] = a[k];
		for(int j = 1;j <= m; j++) {
			if(l[j] <= i && i <= r[j]) continue;
			for(int p = l[j];p <= r[j]; p++) {
				t[p]--;
				fin0[j] = 1;
			}
		}
		minn = 100000000;
		for(int k = 1;k <= n; k++) {
			minn = min(minn, t[k]);
		}
		if(t[i]-minn > ans) {
			memset(fin,0,sizeof(fin));
			ans = t[i]-minn;
			cnt = 0;
			for(int i = 1;i <= 300; i++) 
				if(fin0[i]) {
					fin[i] = 1;
					cnt++;
				}
			
		}
	}
	printf("%d\n%d\n", ans, cnt);
	for(int i = 1;i <= 300; i++) {
		if(fin[i]) printf("%d ",i);
	}
	puts("");
}