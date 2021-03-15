#include <bits/stdc++.h>
using namespace std;

int _, n, a[103];
long long u, v;

bool same() {
	for(int i = 2;i <= n; i++) {
		if(a[i] != a[i-1]) return 0;
	}
	return 1;
}

bool cha1() {
	for(int i = 2;i <= n; i++) {
		if(abs(a[i]-a[i-1]) > 1) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %lld %lld", &n, &u, &v);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		if(same()) {
			printf("%lld\n", min(v+v, v+u));
		}
		else if(cha1()) {
			printf("%lld\n", min(u, v));
		}
		else puts("0");
	}
}