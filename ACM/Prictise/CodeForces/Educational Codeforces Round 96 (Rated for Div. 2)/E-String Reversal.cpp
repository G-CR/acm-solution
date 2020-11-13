#include <bits/stdc++.h>
using namespace std;

int n, pos[30], a[200005];
long long c[200005];
string s;
vector <int> num[30];

int lowbit(int x) {return x&(-x);}

void up(int i, int k) {
	while(i <= n) {
		c[i] += k;
		i += lowbit(i);
	}
}

int qu(int i) {
	int res = 0;
	while(i > 0) {
		res += c[i];
		i -= lowbit(i);
	}
	return res;
}

int main() {
	scanf("%d", &n);
	cin >> s;
	for(int i = 0;i < s.length(); i++) {
		num[s[i]-'a'].push_back(i+1);
	}
//	char a = 'a';
//	for(int i = 0;i < 26; i++) {
//		printf("%c: %d\n", a++, num[i].size());
//	}
	reverse(s.begin(), s.end()); 
	int cnt = 0; 
	for(char i: s) {
		a[++cnt] = num[i-'a'][pos[i-'a']];
		pos[i-'a']++;
	}
//	for(int i = 1;i <= cnt; i++) printf("%d ", a[i]);
	
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += qu(n) - qu(a[i]);
		up(a[i], 1);
	}
	
	printf("%lld\n", ans);
}