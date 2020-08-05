#include <bits/stdc++.h>
using namespace std;

int _, m, n, q;
struct node {
	int x, y, peo;
}a[50005];

bool cmp1(node p, node q) {
	return p.x < q.x;
}

bool cmp2(node p, node q) {
	return p.y < q.y;
}

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d %d", &m, &n, &q);
		int sum = 0;
		for(int i = 1;i <= q; i++) {
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].peo);
			sum += a[i].peo;
		}
		int now = 0, ansx, ansy;
		int mid = (sum+1)/2;
		sort(a+1, a+1+q, cmp1);
		for(int i = 1;i <= q; i++) {
			now += a[i].peo;
			if(now >= mid) {
				if(sum%2) ansx = a[i].x;
				else {
					if(now == mid) ansx = (a[i].x+a[i+1].x)/2;
					else ansx = a[i].x;
				}
				break;
			}
		}
		
		now = 0;
		sort(a+1, a+1+q, cmp2);
		for(int i = 1;i <= q; i++) {
			now += a[i].peo;
			if(now >= mid) {
				if(sum%2) ansy = a[i].y;
				else {
					if(now == mid) ansy = (a[i].y+a[i+1].y)/2;
					else ansy = a[i].y;                           
				}
				break;
			}
		}
		
		printf("Case %d: %d %d\n", ++cas, ansx, ansy);
	}
}