#include <stdio.h>

int n, m;
int a[505][505], sumn[505], summ[505];

int main() {
	int p = 1;
	while(~scanf("%d %d", &n, &m)) {
		int Max1 = -1,Max2 = -1,Maxi,Maxj,t;
		
		for(int i = 1;i <= n; i++) {
			t = 0;
			for(int j = 1;j <= m; j++) {
				scanf("%d", &a[i][j]);
				t += a[i][j];
			}
			sumn[i] = t;
			if(Max1 < sumn[i]) {
				Max1 = sumn[i];
				Maxi = i;
			}
		}
		
		for(int j = 1;j <= m; j++) {
			t = 0;
			for(int i = 1;i <= n; i++) {
				t += a[i][j];
			}
			summ[j] = t;
			if(Max2 < summ[j]) {
				Max2 = summ[j];
				Maxj = j;
			}
		}
		
		int ans = Max2 + Max1 - a[Maxi][Maxj];
		bool ok = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				if(ans < (sumn[i] + summ[j] - a[i][j])) {
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		printf("Case %d: ", p++);
		
		if(!ok) puts("Weak");
		else puts("Strong");
	}
}