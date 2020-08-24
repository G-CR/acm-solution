#include <bits/stdc++.h>
using namespace std;

int _, n;
double sum, num[1000006];

int main() {
	for(int i = 1;i <= 100000000; i++) {
		sum += 1.0/(double)i;
		if(i % 100 == 0) num[i/100] = sum;
	}
	
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		double ans = num[n/100];
		for(int i = n/100*100+1; i <= n; i++) {
			ans += 1.0/(double)i;
		}
		
		printf("Case %d: %.11lf\n", ++cas, ans);
	}
}