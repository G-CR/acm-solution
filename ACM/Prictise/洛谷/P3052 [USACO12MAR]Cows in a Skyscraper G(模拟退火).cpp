#include <bits/stdc++.h>
using namespace std;

int n, W, ans;
int w[20];
bool vis[20];

int getzu() {
	int res = 1;
	int now = 0;
	for(int i = 1;i <= n; i++) {
		if(now + w[i] > W) {
			now = w[i];
			res++;
		}
		else now += w[i];
	}
	return res;
}

void sa() {
	double T = 10000, D = 0.996;
	int cur = n;
	while(T > 1e-14) {
		int pos1 = rand() % n + 1;
		int pos2 = rand() % n + 1;
		swap(w[pos1], w[pos2]);
		int now = getzu();
		if(now < cur) {
			cur = now;
			if(ans > cur) ans = cur;
		}
		else if(exp(ans-now)/T*RAND_MAX > rand()) {
			cur = now;
		}
		else swap(w[pos1], w[pos2]);
		T *= D;
	}
}

void solve() {
	int num = 500;
	while(num--) {
		sa();
	}
}

int main() {
	srand(time(NULL));
	scanf("%d %d", &n, &W);
	ans = n;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &w[i]);
	}
	solve();
	
	printf("%d\n", ans);
}