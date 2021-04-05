#include <bits/stdc++.h>
using namespace std;

int _, n;
int x, a[103];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			a[x]++;
		}
		for(int i = 0; i <= 100; i++) {
			if(a[i]) {
				a[i]--;
				printf("%d ", i);
			}
		}
		
		for(int i = 0; i <= 100; i++) {
			while(a[i]) {
				printf("%d ", i);
				a[i]--;
			}
		}
		puts("");
	}
}