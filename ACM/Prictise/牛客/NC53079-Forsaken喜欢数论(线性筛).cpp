#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e7;
int prime[maxn+5];
int visit[maxn+5];
long long f[maxn+5];

void Prime(){
	memset(visit, 0, sizeof(visit));
	memset(prime, 0, sizeof(prime));
	for (int i = 2;i <= maxn; i++) {
		if (!visit[i]) {
			prime[++prime[0]] = i;
			f[i] = i;
		}
		for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++) {
			visit[i*prime[j]] = 1;
			f[i*prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

int n;

int main() {
	Prime();
	scanf("%d\n", &n);

	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += f[i];
	}
	printf("%lld\n", ans);
}