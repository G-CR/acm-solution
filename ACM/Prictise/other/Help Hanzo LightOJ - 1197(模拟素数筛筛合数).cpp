#include <bits/stdc++.h>
using namespace std;

int _, a, b, cas;
const int M = 1000000;
bool isprime[M+5], vis[100005];
int prime[M+5], cnt;

void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) prime[++cnt] = i;
	}
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &a, &b); if(a == 1) a++;
		for(int i = 1;i <= cnt; i++) {
			int sta = (int)((ceil)((double)a/(double)prime[i]));
			for(int j = max(sta, 2); j <= b/prime[i]; j++) {
				vis[prime[i]*j-a+1] = 1;
			}
		}
		
		int ans = 0;
		for(int i = 1;i <= b-a+1; i++) if(vis[i]) ans++;
		printf("Case %d: %d\n", ++cas, (b-a+1)-ans);
	}
}