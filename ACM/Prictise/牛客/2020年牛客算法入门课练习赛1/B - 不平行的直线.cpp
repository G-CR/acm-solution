#include <bits/stdc++.h>
using namespace std;
const double inf = 1e9;
map <double, bool> vis;
double x[202], y[202];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}
	
	double k;
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = i+1;j <= n; j++) {
			k = x[i]==x[j]?inf:((y[i]-y[j])/(x[i]-x[j]));
			if(vis[k]) continue;
			vis[k] = 1;
			ans++;
		}
	}
	
	printf("%d\n", ans);
}