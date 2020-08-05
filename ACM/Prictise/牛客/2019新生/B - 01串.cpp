#include <bits/stdc++.h>
using namespace std;

char s[300005];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	int start = 1, end = 1;
	int ans = 1;
	for(int i = 2;i <= n; i++) {
		end = i;
		if(s[i] != s[i-1]) {
			ans = max(ans, end-start);
			start = i;
		}
	}
	printf("%d\n", ans);
}