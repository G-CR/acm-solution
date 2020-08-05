#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x0, y00, ax, ay, bx, by, xs, ys, t;
ll px[100], py[100];
vector <pair<ll, ll> > vc;

int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &x0, &y00, &ax, &ay, &bx, &by);
	scanf("%lld %lld %lld", &xs, &ys, &t);
	
	vc.push_back(make_pair(x0, y00));
	while(1) {
		x0 = x0*ax+bx;
		y00 = y00*ay+by;
		if(x0-xs+y00-ys <= t) vc.push_back(make_pair(x0, y00));
		else break;
	}
	
	int n = vc.size();
	
	ll len1, len2, ans = 0;
	for(int i = 0;i < n; i++) {
		len1 = abs(xs-vc[i].first) + abs(ys-vc[i].second);
		for(int j = i;j < n; j++) {
			len2 = abs(xs-vc[j].first) + abs(ys-vc[j].second);
			if(min(len1, len2)+abs(vc[i].first-vc[j].first) + abs(vc[i].second-vc[j].second) <= t) {
				ans = max(ans, (ll)j-i+1);
			}
		}
	}
	printf("%lld\n", ans);
}