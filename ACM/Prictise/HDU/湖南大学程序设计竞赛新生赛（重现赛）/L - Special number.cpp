#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
bool a[N];
int L, R;

void solve() {
	int m = 20;
	for(int i = 1;i <= m; i++) a[i] = 1;
	for(int i = 3;i <= m; i++) if(!(i%2)) a[i] = 0;
	for(int i = 2;i <= m; i++) {
		if(a[i]) {
			for(int j = i*2; j<= m; j += i)
				a[j] = 0;
		}
	}
}

int main() {
	solve();
	scanf("%d %d", &L, &R);
	int ans = 0;
	for(int i = L;i <= R; i++) {
		if(a[i]) ans++;
	}
	printf("%d\n", ans);
}