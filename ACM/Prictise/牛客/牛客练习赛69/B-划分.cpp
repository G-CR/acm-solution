#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005], x, y;
long long pre[100005];

bool cmp(int a, int b) {return a > b;}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n, cmp);
	for(int i = 1;i <= n; i++) pre[i] = pre[i-1] + a[i];
	scanf("%d %d", &x, &y);
	long long ans = 0;
	for(int i = 1;i <= x; i++) {
		for(int j = 1;j <= y; j++) {
//			printf("%lld\n", pre[i*j]);
			ans += pre[i*j];
		}
	}
	
	printf("%lld\n", ans);
}