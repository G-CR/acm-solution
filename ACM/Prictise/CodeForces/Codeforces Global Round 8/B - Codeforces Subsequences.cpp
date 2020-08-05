#include <bits/stdc++.h>
using namespace std;

long long k;
long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x) 
		if (n & 1) res = res * x; 
	return res; 
}

int main() {
	scanf("%lld", &k);
	int cnt;
	for(int i = 1;; i++) {
		if(qpow(i, 10) >= k) {
			cnt = i;
			break;
		} 
	}
	
	long long res = qpow(cnt, 10);
	vector <int> v;
	for(int i = 1;i <= 10; i++) v.push_back(cnt);
	
	for(int i = cnt;i >= 1; i--) {
		for(int j = 0;j < 10; j++) {
//			cout << res << endl;
			if(res/i*(i-1) >= k) {
				res = res/i*(i-1);
				v[j]--;
			}
		}
	}
	
	for(int i = 1;i <= v[0]; i++) printf("c");
	for(int i = 1;i <= v[1]; i++) printf("o");
	for(int i = 1;i <= v[2]; i++) printf("d");
	for(int i = 1;i <= v[3]; i++) printf("e");
	for(int i = 1;i <= v[4]; i++) printf("f");
	for(int i = 1;i <= v[5]; i++) printf("o");
	for(int i = 1;i <= v[6]; i++) printf("r");
	for(int i = 1;i <= v[7]; i++) printf("c");
	for(int i = 1;i <= v[8]; i++) printf("e");
	for(int i = 1;i <= v[9]; i++) printf("s");
}