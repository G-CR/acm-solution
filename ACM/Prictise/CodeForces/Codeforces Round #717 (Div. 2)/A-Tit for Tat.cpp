#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[103];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= n; i++) {
			if(!k || i == n) break;
			while(k && a[i]) {
				a[i]--;
				a[n]++;
				k--;
			}
		}
		
		
		for(int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
}