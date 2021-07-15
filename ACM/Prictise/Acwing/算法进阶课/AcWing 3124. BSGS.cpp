#include <bits/stdc++.h>
using namespace std;

long long a, p, b;

long long bsgs() {
	if(1 % p == b % p) return 0;
	unordered_map<int, int> mp;
	int k = sqrt(p) + 1;
	for(long long i = 0, j = b % p;i <= k-1; i++, j = (j * a) % p) mp[j] = i;
	
	long long ak = 1;
	for(int i = 1;i <= k; i++) ak = ak * a % p;
	
	for(long long i = 1, j = ak; i <= k; i++) {
		if(mp.count(j)) return i*k-mp[j];
		j = (j * ak) % p;
	}
	return -1;
}

int main() {
	while(~scanf("%lld %lld %lld", &a, &p, &b) && a) {
		long long res = bsgs();
		if(res == -1) puts("No Solution");
		else printf("%lld\n", res);
	}
}