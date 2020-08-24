#include <bits/stdc++.h>
using namespace std;
//const long long mod = 9223372036854775807;
int _;
long long fib[2000006];

void init() {
	fib[1] = 1; fib[2] = 2;
	for(int i = 3;i <= 2000000; i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}
}

int main() {
	init();
	int lena, lenb, lenc, x;
	int chc[2000006];
	scanf("%d", &_);
	while(_--) {
		long long a = 0, b = 0, c = 0;
		scanf("%d", &lena); 
		for(int i = 1;i <= lena; i++) {
			scanf("%d", &x);
			if(x) a += fib[i];
		}
		
		scanf("%d", &lenb);
		for(int i = 1;i <= lenb; i++) {
			scanf("%d", &x);
			if(x) b += fib[i];
		}
		
		scanf("%d", &lenc);
		for(int i = 1;i <= lenc; i++) {
			scanf("%d", &chc[i]);
			if(chc[i]) c += fib[i];
		}
		
		long long k = a*b-c;
		int ans = 0;
		for(int i = 1;i <= lenc; i++) {
			if(fib[i] == k) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
}