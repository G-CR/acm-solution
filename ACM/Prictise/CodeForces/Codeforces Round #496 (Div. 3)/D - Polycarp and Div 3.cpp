#include <bits/stdc++.h>
using namespace std;

string s;
int a[200005];

int main() {
	cin >> s;
	int n = s.length();
	for(int i = 0;i < n; i++) {
		a[i+1] = s[i]-'0';
		a[i+1] %= 3;
	}
	
	int now = 0, cnt = 0, ans = 0;
	for(int i = 1;i <= n; i++) {
		now += a[i];
		cnt++;
		if(a[i] == 0 || now == 3 || cnt == 3) {
			now = 0;
			cnt = 0;
			ans++;
		}
	}
	printf("%d\n", ans);
}