#include <bits/stdc++.h>
using namespace std;

int father[200005], sum[200005];
int n, m;

int find(int x) {
	if(x != father[x]) {
		int t = father[x];
		father[x] = find(father[x]);
		sum[x] += sum[t];
	}
	return father[x];
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0;i <= n; i++) {
			father[i] = i;
			sum[i] = 0;
		}
		
		int ans = 0;
		while(m--) {
			int l, r, value;
			scanf("%d %d %d", &l, &r, &value);
			l--;
			int fl = find(l);
			int fr = find(r);
			
			if(fl == fr) {
				if((sum[l]-sum[r]) != value) {
//					printf("l = %d r = %d\n", l, r);
					ans++;
				}
			}
			
			else {
				father[fl] = fr;
				sum[fl] = -sum[l] + sum[r] + value;
			}
		}
		printf("%d\n", ans);
	}
}