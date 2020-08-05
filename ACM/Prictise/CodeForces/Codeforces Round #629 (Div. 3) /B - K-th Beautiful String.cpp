#include <bits/stdc++.h>
using namespace std;

int _, n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		int pos1, pos2;
		for(int i = 1;i <= n; i++) {
			if(k <= i) {
				pos1 = n-i;
				pos2 = n-k+1;
				break;
			}
			k -= i;
		}
		for(int i = 1;i <= n; i++) {
			if(i == pos1 || i == pos2) printf("b");
			else printf("a");
		}
		puts("");
	}
}