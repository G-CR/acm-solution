#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	long long sum = 0;
	sum = (1+n)*n/2;
	if(sum % 2 == 0) puts("0");
	else puts("1");
}