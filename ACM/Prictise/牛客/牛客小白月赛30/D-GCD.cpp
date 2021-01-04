#include <bits/stdc++.h>
using namespace std;

int n;
const int M = 100000;
bool isprime[M+5];

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 1;
}

int main() {
	solve();
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		if(isprime[i]) ans++;
	}
	printf("%d\n", ans==n?-1:ans+1);
}