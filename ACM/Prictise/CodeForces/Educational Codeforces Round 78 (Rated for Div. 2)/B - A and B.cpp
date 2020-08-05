#include <bits/stdc++.h>
using namespace std;

long long a, b;
int t;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &a, &b);
		if(a > b) swap(a,b);
		int i = 1;
		while(a < b || abs(a-b)%2!=0) {
			a += i;
			i++;
		}
		printf("%d\n", i-1);
	}
}