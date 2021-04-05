#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[100005];

bool checkp() {
	for(int i = 2; i <= n; i++) {
		if(a[i] != a[i-1]) return 0;
	}
	return 1;
}

bool checkj() {
	long long cha = a[1]-a[2];
	for(int i = 1; i < n; i++) {
		if(a[i]-a[i+1] != cha) return 0;
	}
	return 1;
}

bool check(long long mod, long long c) {
	if(a[1] != a[1] % mod) return 0;
	for(int i = 1; i < n; i++) {
		if((a[i]+c)%mod != a[i+1]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		if(checkp() || checkj()) {puts("0"); continue;}
		bool ok = 1;
		long long c = 0, p = -1, q = -1;
		for(int i = 1; i < n; i++) {
			if(a[i] == a[i+1]) {ok = 0; break;}
			if(a[i] < a[i+1]) {
				if(c && c != a[i+1]-a[i]) {
					ok = 0;
					break;
				}
				else c = a[i+1]-a[i];
			}
			else {
				p = a[i], q = a[i+1];
			}
		}
		if(ok) {
			long long mod = p+c-q;
			if(p == -1 && q == -1) {
				puts("0");
			}
			else if(check(mod, c)) {
				printf("%lld %lld\n", mod, c);
			}
			else {
				puts("-1");
			}
		}
		else puts("-1");
	}
}