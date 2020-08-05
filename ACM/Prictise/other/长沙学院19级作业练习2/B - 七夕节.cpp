#include <bits/stdc++.h>
using namespace std;

int T, n, sum;

int main() {
	scanf("%d", &T);
	while(T--) {
		sum = 1;
		scanf("%d", &n);
		if(n == 1) {
			puts("1");
			continue;
		}
		for(int i = 2; i <= sqrt(n); i++) {
			if(n % i == 0 && i == n/i) sum += i;
			else if(n % i == 0) sum += (i + n/i);
		}
		printf("%d\n", sum);
	}
}