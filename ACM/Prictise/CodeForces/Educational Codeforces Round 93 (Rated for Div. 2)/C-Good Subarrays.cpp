#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;
int a[100005];
long long pre[100005];
map <long long, int> mp;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s;
		mp.clear();
		int cnt = 0;
		for(char i: s) {
			a[++cnt] = i-'0';
		}
		for(int i = 1;i <= n; i++) pre[i] = pre[i-1] + (long long)a[i] - 1;
		
		long long ans = 0;
		mp[0] = 1;
		for(int i = 1;i <= n; i++) {
			ans += mp[pre[i]];
			mp[pre[i]]++;
		}
		printf("%lld\n", ans);
	}
}