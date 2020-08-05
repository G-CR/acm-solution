#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	if(n % 2) puts("Bob");
	else {
		if(n == 2) puts("Alice");
		else {
			while(n % 2 == 0) n /= 2;
			if(n == 1) puts("Alice");
			else puts("Bob");
		}
	}
}