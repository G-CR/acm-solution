#include <bits/stdc++.h>
using namespace std;

int _, n;
long double a, b, ans, x[100005], y[100005];

double getsum() {
	double sum = 0;
	for(int i = 1;i <= n; i++) {
		sum += sqrt(x[i]*x[i] + y[i]*y[i]);
	}
	return sum;
}

void sa() {
	double T = 10000, D = 0.99;
	double cur = 1e18;
	while(T > 1e-4) {
		int pos1 = rand() % n + 1;
		int pos2 = rand() % n + 1;
		swap(x[pos1], x[pos2]);
		
		double now = getsum();
//		printf("now = %.9f\n", now);
		
		if(now < cur) {
			cur = now;
			if(cur < ans) ans = cur;
		}
		else if(exp((now-cur) / T) * RAND_MAX > rand()) {
			cur = now;
		}
		else swap(x[pos1], x[pos2]);
		
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
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= 2*n; i++) {
			scanf("%Lf %Lf", &a, &b);
			if(a) x[++cnt1] = fabs(a);
			else if(b) y[++cnt2] = fabs(b);
		}
		sort(x+1, x+1+n);
		sort(y+1, y+1+n);
		
		long double ans = 0;
		for(int i = 1;i <= n; i++) {
			ans += sqrt(x[i]*x[i] + y[i]*y[i]);
		}
		
		printf("%.15Lf\n", ans);
	}
}