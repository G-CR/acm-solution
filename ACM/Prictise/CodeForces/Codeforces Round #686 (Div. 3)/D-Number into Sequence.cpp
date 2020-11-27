#include <bits/stdc++.h>
using namespace std;

int _;
long long n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		long long t = n;
		long long dig, num = 0;
		for(int i = 2;i <= (int)(sqrt(n)); i++) {
			int now = 0;
			while(n % i == 0) {
				n /= i;
				now++;
			}
			if(now > num) {
				dig = i;
				num = now;
				now = 0;
			}
		}
//		printf("num = %lld dig = %lld\n", num, dig);
		if(num == 0) {
			puts("1");
			printf("%lld\n", t);
		}
		else {
			printf("%lld\n", num);
			long long sum = 1;
			for(int i = 1;i < num; i++) {
				sum *= dig;
				printf("%lld ", dig);
			}
			printf("%lld\n", t/sum);
		}
	}
}