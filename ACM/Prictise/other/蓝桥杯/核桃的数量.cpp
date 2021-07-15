#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	int k = a*b/__gcd(a, b);
	printf("%d\n", k*c/__gcd(k, c));
}