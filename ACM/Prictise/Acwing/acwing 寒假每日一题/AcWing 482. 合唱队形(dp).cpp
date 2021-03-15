#include <bits/stdc++.h>
using namespace std;

int n;
int a[103];
int pre[103], rpre[103];

int dfs1(int pos) {
	if(pre[pos]) return pre[pos];
	int t = 1;
	for(int i = pos+1;i <= n; i++) {
		if(a[i] < a[pos]) {
			t = max(t, dfs1(i)+1);
		}
	}
	return pre[pos] = t;
}

int dfs2(int pos) {
	if(rpre[pos]) return rpre[pos];
	int t = 1;
	for(int i = pos-1;i >= 1; i--) {
		if(a[i] < a[pos]) {
			t = max(t, dfs2(i)+1);
		}
	}
	return rpre[pos] = t;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1;i <= n; i++) dfs1(i);
	for(int i = n;i >= 1; i--) dfs2(i);
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		ans = max(ans, pre[i]+rpre[i]-1);
	}
	printf("%d\n", n-ans);
}