#include <bits/stdc++.h>
using namespace std;

int n, a[103];

bool check() {
	int k = a[0];
	for(int i = 1; i < n; i++)
		if(a[i] != k) 
			return 0;
		
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = 0;
	while (1) {
		if(check()) break;
		int now = a[n-1];
		for(int i = 0; i < n-1; i++) {
			int k = a[i] / 2;
			a[i] -= k;
			a[((i-1)+n)%n] += k;
		}
		int k = now / 2;
		a[n-1] -= k;
		a[n-2] += k;
		
		for(int i = 0; i < n; i++) {
			if(a[i] % 2) a[i]++, ans++;
		}
	}
	
	printf("%d\n", ans);
}