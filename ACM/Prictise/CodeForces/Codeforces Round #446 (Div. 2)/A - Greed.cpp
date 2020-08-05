#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005], b[100005];
long long cans, cola;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		cola += a[i];
	}
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b+1, b+1+n);
	if(cola <= b[n-1]+b[n]) puts("YES");
	else puts("NO");
}