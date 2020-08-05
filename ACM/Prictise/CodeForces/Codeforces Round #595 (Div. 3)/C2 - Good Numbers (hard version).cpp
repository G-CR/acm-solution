#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t[40], n;
bool choose[40];
int q;

int main() {
	ll k = 1;
	for(int i = 0;i <= 38; i++) {
		t[i] = k; k *= 3;
	}
	
	scanf("%d", &q);
	while(q--) {
		memset(choose, 0, sizeof(choose));
		scanf("%lld", &n);
		int pos;
		for(int i = 0;i <= 38; i++) {
			if(t[i] >= n) {
				pos = i; break;
			}
		}
		if(t[pos] == n) {
			printf("%lld\n", n); continue;
		}
		for(int i = pos;i >= 0; i--) {
			if(n - t[i] == 0) {
				n -= t[i];
				choose[i] = 1; break;
			}
			if(n - t[i] < 0) continue;
			n -= t[i];
			choose[i] = 1;
		}
		
		ll sum = 0;
		if(n == 0) {
			for(int i = 0;i <= pos; i++) {
				if(choose[i]) sum += t[i];
			}
			printf("%lld\n", sum);
			continue;
		}
		for(int i = 0;i <= pos; i++) {
			if(choose[i]) {choose[i] = 0; continue;}
			choose[i] = 1;
			if(n - t[i] <= 0) break;
		}
		
		for(int i = 0;i <= pos; i++) {
			if(choose[i]) sum += t[i];
		}
		
		printf("%lld\n", sum);
		continue;
	}
}