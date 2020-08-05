#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005];
map <int, int> mp;

bool check() {
	for(int i = 2;i <= n; i++) {
		if(a[i] <= a[i-1]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+1+n);
	for(int i = 1;i <= n; i++) {
		mp[b[i]] = i;
	}
	
	int ans = 0;
	while(!check()) {
		for(int i = 1;i <= n; i++) {
			if(a[i] == b[i]) continue;
			swap(a[i], a[mp[a[i]]]); ans++;
		}
	}
	
//	for(int i = 1;i <= n; i++) printf("%d ", a[i]); puts("");
	printf("%d\n", ans);
}