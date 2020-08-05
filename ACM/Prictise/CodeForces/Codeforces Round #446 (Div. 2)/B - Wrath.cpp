#include <bits/stdc++.h>
using namespace std;

int n;
long long len[1000006];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &len[i]);
	}
	
	int killer = n+1, ans = 0;
	long long dao = 0;
	for(int i = n;i >= 1; i--) {
		if(i < killer-dao) {
			ans++;
			killer = i;
			dao = len[i];
		}
		else {
			if(i-len[i] < killer-dao) {
				dao = killer-(i-len[i]);
			}
		}
	}
	printf("%d\n", ans);
}