#include <bits/stdc++.h>
using namespace std;

int _;
double n, c;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf", &n, &c);
		int ans = c/2/n;
		if(ans*(c-n*ans) < (ans+1)*(c-n*(ans+1))) ans++;
		printf("Case %d: %d\n", ++cas, n==0?0:ans);
	}
}