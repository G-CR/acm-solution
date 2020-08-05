#include <bits/stdc++.h>
using namespace std;

int n,x,ans;
struct node {
	int pos;
	int a;
}sst[1005];

bool cmp(node a, node b) {
	if(a.a == b.a) return a.pos > b.pos;
	return a.a > b.a;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &sst[i].a);
		sst[i].pos = i;
	}
	sort(sst+1, sst+1+n, cmp);
	
	for(int i = 1;i <= n; i++) {
		ans += sst[i].a*x + 1;
		x++;
	}
	
	printf("%d\n", ans);
	for(int i = 1;i <= n; i++) {
		printf("%d ", sst[i].pos);
	}
	puts("");
}