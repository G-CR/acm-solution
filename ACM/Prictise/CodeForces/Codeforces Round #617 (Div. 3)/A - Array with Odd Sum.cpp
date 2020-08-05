#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main() {
	scanf("%d", &t);
	while(t--) {
		bool ji = 0, ou = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(x % 2) ji = 1;
			if(x % 2 == 0) ou = 1;
		}
		if(ji && ou) puts("YES");
		else if(n % 2 && ji) puts("YES");
		else puts("NO");
	}
}