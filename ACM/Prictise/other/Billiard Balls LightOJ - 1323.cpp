#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
} poi[1005];

bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int up(int m, int l, int k) {
	int ans = k % (l*2);
	if(ans > (l-m)) {
		if(ans >= 2*l-m) {
			m = ans + m - 2*l;
		}
		else {
			m = 2*l - ans - m;
		}
	}
	else {
		m += ans;
	}
	return m;
}

int down(int m, int l, int k) {
	int ans = k % (l*2);
	if(ans > m) {
		if(ans > l+m) {
			m = 2*l - ans + m;
		}
		else {
			m = ans - m;
		}
	}
	else {
		m -= ans;
	}
	return m;
}

int main() {
	int _, cas = 0;
	scanf("%d", &_);
	while(_--) {
		int l, w, n, k;
		char a, b;
		scanf("%d %d %d %d", &l, &w, &n, &k);
		printf("Case %d:\n", ++cas);
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %c %c", &poi[i].x, &poi[i].y, &a, &b);
			if(a == 'N') poi[i].y = up(poi[i].y, w, k);
			else poi[i].y = down(poi[i].y, w, k);
			
			if(b == 'E') poi[i].x = up(poi[i].x, l, k);
			else poi[i].x = down(poi[i].x, l, k);
		}
		
		sort(poi+1, poi+1+n, cmp);
		for(int i = 1;i <= n; i++) {
			printf("%d %d\n", poi[i].x, poi[i].y);
		}
	}
}