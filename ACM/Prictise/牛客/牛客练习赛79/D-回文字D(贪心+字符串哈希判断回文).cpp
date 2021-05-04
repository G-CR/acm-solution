#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 1e7+7;
const ll P = 107;
int n, d;
char s[N];
ll pre[N], beh[N], p[N];

bool check(int l, int r) {
	return pre[r] - pre[l-1] * p[r-l+1] == beh[l] - beh[r+1] * p[r-l+1];
}

int main() {
	scanf("%d %d %s", &n, &d, (s+1));
	p[0] = 1;
	for(int i = 1; i <= n; i++) {
		pre[i] = s[i] + pre[i-1] * P;
		p[i] = p[i-1] * P;
	}
	for(int i = n; i >= 1; i--) beh[i] = s[i] + beh[i+1] * P;
	
	int ans = 0;
	for(int i = 1, j; i <= n ; i = j+1) {
		j = i + d - 2;
		while(j + 1 <= n && check(j+1-d+1, j+1)) j++;
		ans++;
	}
	
	printf("%d\n", ans);
}