#include <bits/stdc++.h>
using namespace std;

int n, k;
int qpow(int x, int n) { 
	int res = 1; 
	for (; n; n >>= 1, x = x * x) 
		if (n & 1) res = res * x; 
	return res; 
}

int main() {
	scanf("%d %d", &k, &n);
	int res = 0, num = 0;
	while(n) {
		if(n & 1) res += qpow(k, num);
		num++;
		n >>= 1;
	}
	printf("%d\n", res);
}