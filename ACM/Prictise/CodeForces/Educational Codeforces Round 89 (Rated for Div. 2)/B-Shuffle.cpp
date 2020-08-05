#include <bits/stdc++.h>
using namespace std;

int _, n, m, x, l[102], r[102];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &x, &m);
		for(int i = 1;i <= m; i++) {
			scanf("%d %d", &l[i], &r[i]);
		}
		
		int nowl = x, nowr = x;
		for(int i = 1;i <= m; i++) {
			if(l[i] > nowr || r[i] < nowl) continue;
			else {
				nowl = min(nowl, l[i]);
				nowr = max(nowr, r[i]);
			}
		}
		printf("%d\n", nowr-nowl+1);
	}
}