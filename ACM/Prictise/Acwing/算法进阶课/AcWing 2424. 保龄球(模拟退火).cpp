#include <bits/stdc++.h>
using namespace std;

int n, ans = -1;
int a[55], b[55];
bool n1;

int getsum() {
	int sum = 0;
	int db = 0;
	for(int i = 1;i <= n; i++) {
		int now = a[i] + b[i];
		if(db == 1) now *= 2;
		else if(db == 2) now += a[i];
		
		sum += now;
		
		if(a[i] == 10) db = 1;
		else if(a[i] + b[i] == 10) db = 2;
		else db = 0;
	}
	
	if(n1) sum += (a[n+1] + b[n+1]) * 2;
	return sum;
}

void sa() {
	double T = 10000, D = 0.99;
	int cur = -1;
	while(T > 1e-14) {
		int m = n + n1;
		int pos1 = rand() % m + 1;
		int pos2 = rand() % m + 1;
		if(pos1 == pos2 || (n1 && (pos1 == n || pos2 == n))) continue;
		swap(a[pos1], a[pos2]); 
		swap(b[pos1], b[pos2]);
		
		int now = getsum();
		
		if(now > cur) {
			cur = now;
			if(cur > ans) ans = cur;
		}
		else if(exp((now-cur) / T) * RAND_MAX > rand() ) {
			cur = now;
		}
		else {
			swap(a[pos1], a[pos2]); 
			swap(b[pos1], b[pos2]);
		}
		
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
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]);
	if(a[n] == 10 && b[n] == 0) {
		n1 = 1;
		scanf("%d %d", &a[n+1], &b[n+1]);
	}
	solve();
	printf("%d\n", ans);
}