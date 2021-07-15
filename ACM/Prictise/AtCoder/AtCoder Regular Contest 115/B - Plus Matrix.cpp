#include <bits/stdc++.h>
using namespace std;
const int N = 503;
typedef long long ll;

int n;
ll a[N][N];
ll x[N], y[N];

bool same(vector <ll> &x, vector <ll> &y) {
	for(int i = 0; i < x.size(); i++) {
		if(x[i] != y[i]) return 0;
	}
	return 1;
}

bool vis[N][N];

void dfs(int px, int py) {
	if(vis[px][py]) return;
//	printf("px = %d py = %d\n", px, py);
	vis[px][py] = 1;
	if(py-1 >= 1) {
		y[py-1] = y[py] - (a[px][py] - a[px][py-1]);
		dfs(px, py-1);
	}
	if(py+1 <= n) {
		y[py+1] = y[py] + (a[px][py+1] - a[px][py]);
		dfs(px, py+1);
	}
	if(px-1 >= 1) {
		x[px-1] = x[px] - (a[px][py] - a[px-1][py]);
		dfs(px-1, py);
	}
	if(px+1 <= n) {
		x[px+1] = x[px] + (a[px+1][py] - a[px][py]);
		dfs(px+1, py);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	
	vector <ll> cha, tmp;
	for(int i = 2; i <= n; i++) {
		cha.push_back(a[1][i] - a[1][i-1]);
	}
	
	bool ok = 1;
	for(int i = 2; i <= n; i++) {
		tmp.clear();
		for(int j = 2; j <= n; j++) {
			tmp.push_back(a[i][j] - a[i][j-1]);
		}
		if(!same(cha, tmp)) {
			ok = 0;
			break;
		}
	}
	
	if(!ok) puts("No");
	else {
		puts("Yes");
		ll mi = 1e18, px, py;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(mi > a[i][j]) {
					mi = a[i][j];
					px = i; py = j;
				}
			}
		}
		
		x[px] = a[px][py] / 2;
		y[py] = a[px][py] - x[px];
		dfs(px, py);
		
		for(int i = 1; i <= n; i++) printf("%lld ", x[i]); puts("");
		for(int i = 1; i <= n; i++) printf("%lld ", y[i]); puts("");
	}
}