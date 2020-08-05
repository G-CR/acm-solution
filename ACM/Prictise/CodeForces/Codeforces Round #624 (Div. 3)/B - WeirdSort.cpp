#include <bits/stdc++.h>
using namespace std;

int t, n, m, x;
map<int, bool> ok;
int a[105];

bool check() {
	for(int i = 1;i < n; i++) {
		if(a[i] > a[i+1]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		ok.clear();
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1;i <= m; i++) {
			scanf("%d", &x);
			ok[x] = 1;
		}
		
		for(int num = 1;num <= n; num++) {
			for(int i = 1;i < n; i++) {
				if(a[i] > a[i+1] && ok[i]) {
					swap(a[i], a[i+1]);
				}
			}
		}
		puts(check()?"YES":"NO");
	}
}