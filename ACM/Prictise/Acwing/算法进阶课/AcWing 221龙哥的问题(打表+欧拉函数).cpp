#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> p;

long long get_phi(long long n) { // 求单个值的欧拉函数
	long long ans = n;
	for(long long i = 2 ; i * i <= n; i++) {
		if(!(n%i)){
			ans = ans/i*(i-1);
			while(n%i == 0){
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; (long long)i*i <= n; i++) {
		if(n % i == 0) {
			p.push_back(i);
			if(i != n/i) p.push_back(n/i);
		}
	}
	
	long long ans = 0;
	for(int i = 0;i < p.size(); i++) {
		int t = n / p[i];
		ans += 1ll* get_phi(t) * p[i];
	}
	
	printf("%lld\n", ans);
}