#include <bits/stdc++.h>
using namespace std;

int pre[100000];
int _, a, b, q;
long long l, r;

long long cal(long long num, int n) {
	return pre[n-1] * (num/n) + pre[num%n];
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &a, &b, &q);
		int n = a*b;
		for(int i = 1;i < n; i++) {
			pre[i] = pre[i-1];
			if(i%a%b != i%b%a) pre[i]++;
		}
		while(q--) {
			scanf("%lld %lld", &l, &r);
			printf("%lld ", cal(r, n)-cal(l-1, n));
		}
		puts("");
	}
}