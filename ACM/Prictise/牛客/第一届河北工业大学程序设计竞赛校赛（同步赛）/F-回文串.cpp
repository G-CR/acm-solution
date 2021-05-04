#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

char s[N];
int num[500];

int main() {
	scanf("%s", (s+1));
	int n = strlen((s+1));
	for(int i = 1; i <= n; i++) {
		num[s[i]]++;
	}
	int ans = 0;
	for(int i = 'a'; i <= 'z'; i++) {
		if(num[i] % 2) ans++;
	}
	if(ans == 0) puts("1");
	else printf("%d\n", ans);
}