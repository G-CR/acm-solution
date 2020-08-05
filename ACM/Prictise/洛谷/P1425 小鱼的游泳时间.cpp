#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int sum1 = 60*a+b;
	int sum2 = 60*c+d;
	
	printf("%d %d\n", (sum2-sum1)/60, (sum2-sum1)%60);
}