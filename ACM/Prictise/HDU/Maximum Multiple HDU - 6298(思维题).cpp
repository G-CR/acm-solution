#include <iostream>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		if(n % 3 == 0) {
			long long a = n/3;
			printf("%lld\n", a*a*a);
		}
		else if(n % 4 == 0) {
			long long a = n/4;
			printf("%lld\n", a*a*a*2);
		}
		else puts("-1");
	}
}
