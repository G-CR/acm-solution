#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[33], b[33], c[33];
int len1, len2;
long long ans;

long long getsum() {
	long long res1 = 0, res2 = 0;
	for(int i = 1;i <= len1; i++) {
		res1 += 1ll*b[i];
	}
	for(int i = 1;i <= len2; i++) {
		res2 += 1ll*c[i];
	}
	return abs(res1-res2);
}

void sa() {
	double T = 10000, D = 0.996;
	long long cur = 1e18;
	while(T > 1e-14) {
		int pos1 = rand() % len1 + 1;
		int pos2 = rand() % len2 + 1;
		swap(b[pos1], c[pos2]);
		long long now = getsum();
		if(cur > now) {
			cur = now;
			if(ans > cur) ans = cur;
		}
		else if(exp(ans-now) / T * RAND_MAX > rand()) {
			cur = now;
		}
		else swap(b[pos1], c[pos2]);
		T *= D;
	}
}

void solve() {
	int num = 100;
	while(num--) {
		sa();
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if(n == 1) {
			printf("%d\n", a[1]);
			continue;
		}
		int num = n/2;
		len1 = 0, len2 = 0;
		for(int i = 1;i <= n; i++) {
			if(i <= num) b[++len1] = a[i];
			else c[++len2] = a[i];
		}
		ans = getsum();
		solve();
		printf("%lld\n", ans);
	}
}