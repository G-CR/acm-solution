#include <bits/stdc++.h>
using namespace std;

int n, x, a[103];
int num[100005];

int main() {
	scanf("%d", &n);
	int a, b, ma = -1;
	int cnt = 0;
	while(~scanf("%d", &x)) {
		num[x]++;
		if(num[x] > 1) b = x;
		ma = max(ma, x);
	}
	
	for(int i = ma;; i--) {
		if(!num[i]) {
			a = i;
			break;
		}
	}
	
	printf("%d %d\n", a, b);
	return 0;
}