#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int cal(int a, int b, int x, int y) {
	return min(2*a+x+y, 2*b+a+y);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	
	int sta = n%2==1?4:3;
	long long sum = sta==4?a[1]+a[2]+a[3]:a[2];
	for(int i = sta;i <= n; i += 2) {
		sum += cal(a[1], a[2], a[i], a[i+1]);
	}
	
	printf("%lld\n", sum);
}