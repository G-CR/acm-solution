#include <bits/stdc++.h>
using namespace std;

int n, a[] = {1,2,3,4,5,6,7,8,9};

int getd(int l, int r) {
	int res = 0;
	for(int i = l; i <= r; i++) {
		res = res * 10 + a[i];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	int ans = 0;
	do {
		for(int l = 0; l < 9; l++) {
			int a = getd(0, l);
			if(a > n) break;
			for(int r = l+1; r < 8; r++) {
				int b = getd(l+1, r);
				int c = getd(r+1, 8);
				if(b % c) continue;
				if(a+b/c == n) ans++;
			}
		}
	} while(next_permutation(a, a+9));
	
	printf("%d\n", ans);
}