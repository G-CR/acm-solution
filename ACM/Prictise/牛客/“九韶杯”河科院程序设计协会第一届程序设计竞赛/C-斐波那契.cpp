#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[20];
vector <ll> g;

ll lcm(ll a, ll b) {
	return (__int128)(a*b)/__gcd(a, b);
}

int main() {
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= 14; i++) f[i] = f[i-1] + f[i-2];
	for(int i = 2; i <= 14; i++) {
		g.push_back(f[i]*f[i-1]);
	}
	
	__int128 lc = lcm(g[0], g[1]);
	for(int i = 2; i < g.size(); i++) {
		lc = lcm(lc, g[i]);
	}
	
	__int128 sum = 0;
	for(int i = 0; i < g.size(); i++) {
		sum += lc / g[i];
	}
	
	__int128 gcd = __gcd(sum, lc);
	sum /= gcd; lc /= gcd;
	cout << (ll)sum << "/" << (ll)lc << endl;
}