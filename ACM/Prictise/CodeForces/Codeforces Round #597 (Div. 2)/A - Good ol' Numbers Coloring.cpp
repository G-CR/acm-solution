#include <bits/stdc++.h>
using namespace std;

int a, b, t;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		if(gcd(max(a,b), min(a,b)) == 1) puts("Finite");
		else puts("Infinite");
	}
}