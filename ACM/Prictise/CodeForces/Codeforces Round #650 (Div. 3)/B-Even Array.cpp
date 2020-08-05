#include <bits/stdc++.h>
using namespace std;

int _, n, a[45];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int numo = 0, numj = 0;
		for(int i = 0;i < n; i++) {
			scanf("%d", &a[i]);
			if(i%2 != a[i]%2) {
				if(a[i]%2 == 0) numo++;
				else numj++;
			}
		}
		if(numo != numj) puts("-1");
		else {
			printf("%d\n", numo);
		}
	}
}