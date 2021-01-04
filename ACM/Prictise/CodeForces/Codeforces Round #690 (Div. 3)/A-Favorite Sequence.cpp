#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[303];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int l = 1, r = n;
		while(l <= r) {
			if(l < r) printf("%d %d ", a[l], a[r]);
			else printf("%d ", a[l]);
			l++; r--;
		}
		puts("");
	}
}