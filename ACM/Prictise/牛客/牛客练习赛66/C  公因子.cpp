#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000006], Min = 1e18;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		Min = min(Min, a[i]);
	}
	
	vector <long long> v; v.clear();
	for(int i = 2;i <= n; i++) {
		v.push_back(abs(a[i]-a[i-1]));
	}
	
	int cnt = v.size();
	long long t = gcd(v[0], v[1]);
	for(int i = 2;i < cnt; i++) {
		t = gcd(t, v[i]);
	}
	
	long long ans = 0;
	if(t != 1) {
		if(Min == t) ans = 0;
		else if(Min > t) ans = (Min/t+1)*t-Min;
		else {
			ans = abs(Min)-abs((Min/t)*t);
		} 
	}
	
	printf("%lld %lld\n", t, ans);
}