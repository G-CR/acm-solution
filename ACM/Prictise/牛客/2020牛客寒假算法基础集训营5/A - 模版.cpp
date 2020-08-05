#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n1,n2;

int main() {
	scanf("%d %d", &n1, &n2);
	cin >> s1 >> s2;
	int ans = 0;
	int n = min(n1, n2);
	for(int i = 0;i < n; i++) {
		if(s1[i] != s2[i]) ans++;
	}
	ans += max(n1, n2)-n;
	printf("%d\n", ans);
}