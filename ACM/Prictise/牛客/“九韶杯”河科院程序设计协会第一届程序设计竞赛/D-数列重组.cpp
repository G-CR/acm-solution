#include <bits/stdc++.h>
using namespace std;

int a[] = {2,5,3,6,3,6,7,3,7,8};

bool check(int l, int r) {
	bool ok1 = 1, ok2 = 1;
	for(int i = l+1; i <= r; i++) {
		if(a[i-1] < a[i]) {
			ok1 = 0;
			break;
		}
	}
	
	for(int i = l+1; i <= r; i++) {
		if(a[i-1] > a[i]) {
			ok2 = 0;
			break;
		}
	}
	
	return ok1 || ok2;
}

int main() {
	int ans = 0;
	sort(a, a+10);
	do {
		bool ok = 0;
		for(int i = 0; i < 8; i++) {
			for(int j = i+1; j < 9; j++) {
				if(check(0, i) && check(i+1, j) && check(j+1, 9)) {
					ans++;
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
	} while(next_permutation(a, a+10));
	
	printf("%d\n", ans);
}