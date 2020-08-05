#include <bits/stdc++.h>
using namespace std;

int n,ans;
char s[200005];

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	for(int i = 1;i <= n; i += 2) {
		if(s[i] == s[i+1]) {
			if(s[i] == 'a') s[i] = 'b';
			else s[i] = 'a';
			ans++;
		}
	}
	printf("%d\n%s\n", ans, s+1);
}