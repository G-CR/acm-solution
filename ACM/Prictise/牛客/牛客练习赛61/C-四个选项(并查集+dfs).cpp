#include <bits/stdc++.h>
using namespace std;

int a[5], m, ans;
int fa[20], siz[20];
bool vis[12];
vector <int> num;

int fin(int x) {
	if(x == fa[x]) return x;
	return fa[x] = fin(fa[x]);
}

long long fac[20]; // 阶乘表
void solve() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i < 20; i++) {
		fac[i] = (fac[i-1]*i);
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]/fac[k]/fac[n-k]); 
}

void dfs(int pos) {
//	cout << "pos = " << pos << endl;
	if(pos == num.size()) {
		ans++;
		return;
	}
	
	for(int i = 1;i <= 4; i++) {
		if(num[pos] <= a[i]) {
//			printf("%d xuan %d\n", pos, i);
			a[i] -= num[pos];
			dfs(pos+1);
			a[i] += num[pos];
		}
	}
}

int main() {
	solve();
	for(int i = 1;i <= 12; i++) fa[i] = i, siz[i] = 1;
	scanf("%d %d %d %d %d", &a[1], &a[2], &a[3], &a[4], &m);
//	cout << comb(12,a) * comb(12-a,b) * comb(12-a-b, c) << endl;
	
	for(int i = 1;i <= m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		int fu = fin(u), fv = fin(v);
		if(fu == fv) continue;
		fa[fv] = fu;
		siz[fu] += siz[fv];
	}
	
	for(int i = 1;i <= 12; i++) {
		int x = fin(i);
		if(vis[x]) continue;
		vis[x] = 1;
		num.push_back(siz[x]);
	}
	
//	for(int i: num) printf("%d ", i); puts("");
	dfs(0);
	printf("%d\n", ans);
}