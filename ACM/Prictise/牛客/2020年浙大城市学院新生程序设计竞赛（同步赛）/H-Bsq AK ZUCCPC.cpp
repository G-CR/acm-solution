#include <bits/stdc++.h>
using namespace std;

int _, n;
long long m, a[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %lld", &n, &m);
		long long sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		sort(a+1, a+1+n);
		
		long long t = a[1]+a[2]-m;
		t = t > 0?t:0;
		for(int i = 3;i <= n; i++) {
			long long sheng = m - t;
			if(sheng >= a[i]) {t = 0; break;}
			t = a[i]-sheng;
		}
		long long ak1 = t;
		long long ak2 = a[1];
		printf("%lld %lld\n", ak1, ak2);
		
		long long bl1 = sum < m?m-sum:0;
		long long bl2 = m-a[n];
		printf("%lld %lld\n", bl1, bl2);
	}
}