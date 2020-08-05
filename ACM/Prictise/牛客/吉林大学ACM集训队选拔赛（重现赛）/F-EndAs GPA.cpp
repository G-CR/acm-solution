#include <bits/stdc++.h>
using namespace std;

int n;
long long a[25], p[25];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n; i++) scanf("%lld", &p[i]);
	
	double sum = 0;
	for(int i = 1;i <= n; i++) {
		sum += a[i]*p[i];
	}
	sum *= 4;
	
//	cout << sum << endl;
	if(sum >= 39990) puts("Yes");
	else puts("No");
}