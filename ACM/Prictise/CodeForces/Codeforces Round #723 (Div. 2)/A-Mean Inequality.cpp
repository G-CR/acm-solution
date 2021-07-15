#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int _, n;
int a[N];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n); n *= 2;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		for(int i = 1; i <= n/2; i++) {
			printf("%d %d ", a[i], a[i+n/2]);
		}
		puts("");
	}
}