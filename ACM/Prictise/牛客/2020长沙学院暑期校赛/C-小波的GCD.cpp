//https://ac.nowcoder.com/acm/contest/7697#question
#include<bits/stdc++.h>
using namespace std;
 
int _, n;
int a[1000006];
 
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
 
int main() {
	scanf("%d", &n);
	scanf("%d", &a[1]);
	int gc = a[1];
	for(int i = 2;i <= n; i++) {
		scanf("%d", &a[i]);
		gc = gcd(gc, a[i]);
	}
	 
	long long sum = 0;
	for(int i = 1;i <= n; i++) {
		sum += a[i]/gc;
	}
	 
	printf("%lld\n", sum);
}