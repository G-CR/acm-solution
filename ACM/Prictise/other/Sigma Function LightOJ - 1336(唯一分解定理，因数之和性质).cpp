#include <bits/stdc++.h>
using namespace std;

int _, cas;
long long n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		printf("Case %d: ", ++cas);
		printf("%lld\n", n-(long long)sqrt(n)-(long long)(sqrt(n/2)));
	}
}

// 打表代码
#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	for(int k = 1;k <= n; k++) {
		long long sum = 0;
		for(int i = 1;i <= sqrt(k); i++) {
			if(k%i==0) {
				sum += i;
				if(i != k/i) sum += k/i;
			} 
		}
		printf("%d %d\n", k, sum%2==0);
	}
}