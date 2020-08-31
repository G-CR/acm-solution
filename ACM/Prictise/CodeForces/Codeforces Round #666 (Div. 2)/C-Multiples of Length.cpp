#include<iostream>
using namespace std;

long long n,a[100007];

bool check(int n) {
	if(n == 1) return 1;
	return 0;
}

int main(){
	scanf("%lld",&n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	if(check(n)) {
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		puts("1 1");
		printf("%lld\n", -a[1]);
		return 0;
	}
	
	printf("1 %lld\n", n-1);
	for(int i = 1; i < n; i++) {
		long long t = a[i]*(n-1);
		printf("%lld ", t);
		a[i] += t;
	}
	puts("");
	
	printf("%lld %lld\n", n, n);
	printf("%lld\n", -a[n]);
	
	printf("1 %lld\n", n);
	for(int i = 1; i < n; i++) {
		printf("%lld ", -a[i]);
	}
	puts("0");
}