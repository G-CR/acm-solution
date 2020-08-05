#include <bits/stdc++.h>
using namespace std;

const int M = 40;
bool isprime[M];
int a[30], n;
bool vis[30];

void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
}

void dfs(int cnt) {
	if(cnt-1 == n && isprime[a[1]+a[cnt-1]]) {
		for(int i = 1;i < n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
	}
	else {
		for(int i = 2;i <= n; i++) {
			if(!vis[i]) {
				if(isprime[i+a[cnt-1]]) {
					vis[i] = 1;
					a[cnt++] = i;
					dfs(cnt);
					vis[i] = 0;
					cnt--;
				}
			}
		}
	}
}

int main() {
	solve();
	int cases = 0;
	a[1] = 1;
	while(~scanf("%d", &n)) {
		printf("Case %d:\n", ++cases);
		dfs(2); puts("");
	}
}