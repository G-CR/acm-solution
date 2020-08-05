#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, d, x, ans, db[65];
bool ok;

void dabiao() {
	ll k = 1;
	for(int i = 0;i <= 60; i++) {
		db[i] = k; k *= 2;
	}
}

int main() {
	dabiao();
	scanf("%lld", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%lld %lld", &d, &x);
		printf("Case %d: ",p);
		ll pos = 0;
		int cnt = 0; 
		ok = 0;
		for(int i = d;i >= 0; i--) {
			if(pos == x) {ok = 1;break;}
			if(pos < x) pos += db[i];
			else if(pos > x)  pos -= db[i];
			cnt++;
		}
		if(pos == x) {ok = 1;}
		if(ok==1) printf("YES %d\n", cnt);
		else puts("NO");
	}
	return 0;
}