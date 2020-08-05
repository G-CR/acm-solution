#include <bits/stdc++.h>
using namespace std;

long long ans;
int a, b, c, d;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for(int i = a;i <= b; i++) {
		int l = i+b-1;
		int r = i+c-1;
		long long totl = 0, totr = 0, exl = 0, exr = 0;
		if(l >= c) totl = l-c+1;
		if(r >= c) totr = r-c+1;
		ans += (totl+totr)*abs(totr-totl+1)/2;
		
		if(l > d) exl = l-d;
		if(r > d) exr = r-d;
		ans -= (exl+exr)*abs(exr-exl+1)/2;
	}
	
	printf("%lld\n", ans);
}   