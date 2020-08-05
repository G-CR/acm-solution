#include <bits/stdc++.h>
using namespace std;

int _, n, a[10004];
int phi[1000006], isPrime[1000006];

void Eular() { // 欧拉函数
	for(int i = 1;i <= 1000006; i++) phi[i] = i;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	phi[1] = 0;
	for(int i = 2;i <= 1000006; i++) {
		if(isPrime[i]) {
			for(int j = i;j <= 1000006; j+=i) {
				isPrime[j] = false;
				phi[j] -= phi[j]/i;
			}
		}
	}
}

int main() {
	Eular();
//	for(int i = 1;i <= 20; i++) printf("%d %d\n", biao[i].num, biao[i].eula);
	scanf("%d", &_);
	for(int cas = 1;cas <= _; cas++) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		long long ans = 0;
		int k = 1;
		for(int i = 1;i <= n; i++) {
			while(phi[k] < a[i]) k++;
				ans += k;
//			cout << biao[k].num << " ";
		}
//		puts("");
		printf("Case %d: %lld Xukha\n", cas, ans);
	}
}