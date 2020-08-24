#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y, fenzi, fenmu;
bool ok;

map <pair<long long, long long>, bool> vis;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int bfs(long long x, long long y) {
	queue <pair<long long, long long> > q;
	q.push(make_pair(x, y));
	vis[make_pair(x, y)] = 1;
	while(!q.empty()) {
		pair <long long, long long> t = q.front(); q.pop();
		for(long long i = -1; i <= 1; i++) {
			for(long long j = -1; j <= 1; j++) {
				long long ti = t.first+i, tj = t.second+j;
				if(gcd(ti, tj) > 1) {
					if(ti == tj) return 0;
					else {
						fenmu++;
						if(!vis[make_pair(ti, tj)]) {
							q.push(make_pair(ti, tj));
							vis[make_pair(ti, tj)] = 1;
						}
						
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ok = 1;
		vis.clear();
		fenzi = 0, fenmu = 0;
		scanf("%lld %lld", &x, &y);
		for(long long i = -1; i <= 1; i++) {
			for(long long j = -1; j <= 1; j++) {
				if(gcd(x+i, y+j) > 1) {
					fenzi++;
				}
			}
		}
		ok = bfs(x, y);
		if(!ok) {puts("0/1"); continue;}
		long long yue = gcd(fenzi, fenmu);
		printf("%lld/%lld\n", fenzi/yue, fenmu/yue);
	}
}