#include <bits/stdc++.h>
using namespace std;

int ans, a[25], n, k;
bool isprime(int num) {
	if(num < 2) return 0;
	if(num == 2) return 1;
	int t = sqrt((double(num)));
	for(int i = 2;i <= t; i++) {
		if(num % i == 0) return 0;
	}
	return 1;
}

void dfs(int pos, int choose, int sum) {
	if(pos == n) {
		if(choose == k && isprime(sum)) {
			ans++;
		}
		return;
	}
	dfs(pos+1, choose, sum);
	dfs(pos+1, choose+1, sum+a[pos+1]);
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(0,0,0);
	printf("%d\n", ans);
}