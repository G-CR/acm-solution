#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2; i < N; i++) {
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0; j < pn && 1ll*i*prime[j] < N; j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

vector <pair <int, int> > g;
vector <int> ys;
int _;
int a0, a1, b0, b1;

void dfs(int pos, int now) {
	if(pos == g.size()) {
		ys.push_back(now);
		return;
	}
	
	int dig = g[pos].first;
	int num = g[pos].second;
	
	for(int i = 0; i <= num; i++) {
		dfs(pos+1, now);
		now *= dig;
	}
}

int main() {
	getprime();
	scanf("%d", &_);
	while(_--) {
		g.clear(); ys.clear();
		scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
		
		int t = b1;
		for(int i = 0; i < pn; i++) {
			if(prime[i] > t) break;
			bool ok = 0;
			int num = 0;
			while(t % prime[i] == 0) {
				ok = 1;
				num++;
				t /= prime[i];
			}
			if(ok) g.push_back({prime[i], num});
		}
		if(t != 1) g.push_back({t, 1});
		
		dfs(0, 1);
		
		int ans = 0;
		for(int i = 0; i < ys.size(); i++) {
			if(__gcd(ys[i], a0) == a1 && 1ll*ys[i]*b0/__gcd(ys[i],b0) == b1) {
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
}