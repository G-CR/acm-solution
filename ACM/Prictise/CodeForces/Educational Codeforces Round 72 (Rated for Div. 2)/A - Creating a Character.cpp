#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	int a,b,c;
	while(t--) {
		scanf("%d %d %d", &a, &b, &c);
		if(a+c <= b) {
			puts("0");
			continue;
		}
		if(a > b+c) {
			printf("%d\n", c+1);
			continue;
		}
		int t = (a+b+c)/2;
		int ans = t - b;
		if((a+b+c)%2 != 0) ans++;
		printf("%d\n", ans);
	}
}