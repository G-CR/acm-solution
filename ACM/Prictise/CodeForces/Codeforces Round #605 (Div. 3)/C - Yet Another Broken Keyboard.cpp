#include <bits/stdc++.h>
using namespace std;

bool ok[26];
int n, k;
string s;
char c;

long long cal(int l, int r) {
	long long t = (long long)r-(long long)l+1;
	return (1+t)*t/2;
}

int main() {
	scanf("%d %d", &n, &k);
	cin >> s;
	for(int i = 0;i < k; i++) {
		scanf(" %c", &c);
		ok[c-'a'] = 1;
	}
	
	int len = s.length();
	bool xin = 0, con = 0;
	int l, r;
	long long ans = 0;
	
	l = 1; r = 0;
	for(int i = 0;i < len; i++) {
		if(xin && !ok[s[i]-'a']) {
			xin = 0;
			ans += cal(l, r);
			continue;
		}
		
		if(!xin && ok[s[i]-'a']) {
			l = r = i;
			xin = 1;
		}
		
		if(xin && ok[s[i]-'a']) {
			r = i;
		}
		
		if(i == n-1 && ok[s[i]-'a']) con = 1;
	}
	if(con) ans += cal(l, r);
	printf("%lld\n", ans);
}