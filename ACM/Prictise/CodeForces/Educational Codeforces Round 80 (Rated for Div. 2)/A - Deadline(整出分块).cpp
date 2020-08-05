#include <bits/stdc++.h>
using namespace std;

int T, n, d;

int main() {
	scanf("%d", &T);
	while(T--) {
		bool ok = 0;
		scanf("%d %d", &n, &d);
		if(n >= d) puts("YES");
		else {
			for(int i = 1,r = 0;i <= n; i = r+1)
			{
				r = n/(n/i);
				if(r + ceil((double)d/((double)r+1)) <= n) {
					ok = 1;
					break;
				}
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
}