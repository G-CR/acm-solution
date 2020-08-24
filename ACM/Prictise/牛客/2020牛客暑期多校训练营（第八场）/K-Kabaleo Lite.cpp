#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[100005], b[100005];
stack <pair <long long, long long> > sta;

inline void write(__int128 x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main() {
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			a[i] = a[i] + a[i-1];
		}
		b[0] = 1e9;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &b[i]);
			b[i] = min(b[i], b[i-1]);
		}
		
		sta.push(make_pair(a[1], b[1]));
		for(int i = 2;i <= n; i++) {
			pair <long long, long long> t = sta.top(); sta.pop();
			if(a[i] > t.first) {
				if(b[i] == t.second) sta.push(make_pair(a[i], b[i]));
				else {
					t.second -= b[i];
					sta.push(t);
					sta.push(make_pair(a[i], b[i]));
				}
			}
			else sta.push(t);
		}
		
		__int128 ans = 0;
		while(!sta.empty()) {
			__int128 u = sta.top().first, v = sta.top().second;
			sta.pop();
			ans += u*v;
		}
		
		printf("Case #%d: %lld ", ++cas, b[1]);
		write(ans); puts("");
	}
}