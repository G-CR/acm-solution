#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[50], b[50];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]); sort(a+1,a+1+n);
		for(int i = 1;i <= n; i++) scanf("%d", &b[i]); sort(b+1, b+1+n, cmp);
		
		for(int i = 1;i <= k; i++) {
			if(a[i] < b[i]) swap(a[i], b[i]);
		}
		
		int sum = 0;
		for(int i = 1;i <= n; i++) sum += a[i];
		printf("%d\n", sum);
	}
}