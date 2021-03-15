#include <bits/stdc++.h>
using namespace std;

int _, n, a[103], dep[103];

void dfs(int l, int r, int id) {
	if(l > r) return;
	int ma = -1, pos;
	for(int i = l;i <= r; i++) {
		if(ma < a[i]) {
			ma = a[i];
			pos = i;
		}
	}
	dep[pos] = id;
	dfs(l, pos-1, id+1);
	dfs(pos+1, r, id+1);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		dfs(1, n, 0);
		
		for(int i = 1;i <= n; i++) {
			printf("%d ", dep[i]);
		}
		puts("");
	}
}