#include <bits/stdc++.h>
using namespace std;

int _, n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		int t = n-(k-1);
		if(t > 0 && t%2) {
			puts("YES");
			for(int i = 1;i < k; i++) printf("1 ");
			printf("%d\n", t);
		}
		else {
			t = n-(2*(k-1));
			if(t > 0 && t%2 == 0) {
				puts("YES");
				for(int i = 1;i < k; i++) printf("2 ");
				printf("%d\n", t);
			}
			else puts("NO");
		}
	}
}