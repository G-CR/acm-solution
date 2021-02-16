#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
	scanf("%d", &n);
	bool ok = 1;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+1+n);
	if(a[n] > n) puts("-1");
	else {
		int len = n-a[n], ans = 1;
		for(int i = 1;i <= len; i++) {
			int to = i;
			while(to <= len && to-i+1 < a[to]) to++;
			i = to;
			if(i > len) break;
			ans++;
		}
		printf("%d\n", ans);
	}
}