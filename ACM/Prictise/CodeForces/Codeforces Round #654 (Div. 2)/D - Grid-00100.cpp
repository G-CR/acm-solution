#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[305][305];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) for(int j = 1;j <= n; j++) a[i][j] = 0;
		printf("%d\n", k%n==0?0:2);
		
		int i = 1, j = 1, nn = n;
		int num = 1;
		while(k) {
			int cnt = 0, i = 1, j = num;
			for(;cnt < n; i++, j++, cnt++) {
				if(!k) break;
				if(j > n) j -= n;
//				printf("%d %d\n", i, j);
				a[i][j] = 1;
				k--;
			}
			num++;
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				printf("%d", a[i][j]);
			}
			puts("");
		}
	}
}