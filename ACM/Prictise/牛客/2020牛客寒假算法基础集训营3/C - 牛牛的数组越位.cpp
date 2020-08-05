#include <bits/stdc++.h>
using namespace std;

int a[20000007];
int T, n, m, p, x, y, val;

int main() {
	scanf("%d", &T);
	while(T--) {
		int ok = 1;
		for(int i = 0;i < n*m; i++) a[i] = 0;
		scanf("%d %d %d", &n, &m, &p);
		
		while(p--) {
			scanf("%d %d %d", &x, &y, &val);
			if(ok == -1) continue;
			if(x < 0 || y < 0 || x >= n || y >= m) ok = 0;
			int k = x*m+y;
			if(k < 0 || k >= m*n) {ok = -1; continue;}
			a[k] = val;
		}
		
		if(ok == -1) {
			printf("Runtime error");
			if(T >= 1) puts("");
			continue;
		}
		for(int i = 1;i <= n*m; i++) {
			if(i%m == 1 || i == 1 || m == 1) printf("%d", a[i-1]);
			else printf(" %d", a[i-1]);
			if(i%m == 0) puts("");
		}
		if(ok == 1) printf("Accepted");
		if(ok == 0) printf("Undefined Behaviour");
		if(T >= 1) puts("");
	}
}