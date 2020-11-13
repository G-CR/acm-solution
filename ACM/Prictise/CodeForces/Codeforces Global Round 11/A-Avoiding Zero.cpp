#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[100];

bool cmp(int c, int d) {return c > d;}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int sum = 0, sumf = 0, sumz = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
			if(a[i] > 0) sumz += a[i];
			else sumf += a[i];
		}
		if(sum == 0) {puts("NO"); continue;}
		puts("YES");
		if(abs(sumz) > abs(sumf)) sort(a+1, a+1+n, cmp);
		else sort(a+1, a+1+n);
		for(int i = 1;i <= n; i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
}