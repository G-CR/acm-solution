#include <bits/stdc++.h>
using namespace std;

const int M = 10000007;
bool isprime[M];
int pre[10000007], _;

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
	for(int i = 1;i <= M; i++) {
		pre[i] = pre[i-1] + isprime[i];
	}
}

int main() {
	solve();
//	for(int i = 1;i <= 10; i++) cout << pre[i] << " ";
	scanf("%d", &_);
	while(_--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", pre[b]-pre[a-1]);
	}
}