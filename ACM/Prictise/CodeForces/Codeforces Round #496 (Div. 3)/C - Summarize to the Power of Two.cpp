#include <bits/stdc++.h>
using namespace std;

long long x[40], a[120005];
int n, num;
map <long long, int> mp;

void init() {
	long long cnt = 2, i = 0;
	while(cnt <= 10000000000) {
		num++;
		x[++i] = cnt;
		cnt *= 2;
	}
}

bool check(long long k) {
	for(int i = 1;i <= num; i++) {
		if(mp[x[i]-k]) {
			if(k != x[i]-k) return 1;
			else if(mp[x[i]-k] > 1) return 1;
		} 
	}
	return 0;
}


int main() {
	init();
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		mp[a[i]]++;
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		if(!check(a[i])) ans++;
	}
	printf("%d\n", ans);
}