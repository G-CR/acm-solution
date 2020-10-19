#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[105];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = n;i >= 1; i--) {
			printf("%d ", a[i]);
		}
		puts("");
	}
}