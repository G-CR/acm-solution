#include <bits/stdc++.h>
using namespace std;

int n, a[200005];
int xd[200005], dx[200005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	
	int cntxd = 0, cntdx = 0;
	xd[++cntxd] = a[1];
	if(n > 1) dx[++cntdx] = a[2];
	
	for(int i = 3;i <= n; i++) {
		if(a[i] != xd[cntxd]) xd[++cntxd] = a[i];
		else if(a[i] != dx[cntdx]) dx[++cntdx] = a[i];
		else break;
	}
	
	if(cntxd+cntdx < n) puts("NO");
	else {
		puts("Yes");
		sort(dx+1, dx+1+cntdx, cmp);
		printf("%d\n", cntxd);
		for(int i = 1;i <= cntxd; i++) printf("%d ", xd[i]); puts("");
		
		printf("%d\n", cntdx);
		for(int i = 1;i <= cntdx; i++) printf("%d ", dx[i]); puts("");
		
	}
	
	
}