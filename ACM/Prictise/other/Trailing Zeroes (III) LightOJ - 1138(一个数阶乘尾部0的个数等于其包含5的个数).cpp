#include <bits/stdc++.h>
using namespace std;

int _, n, cas;

int get0(int dig) {
	int res = 0;
	while(dig >= 5) {
		res += dig/5;
		dig /= 5;
	}
	return res;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		printf("Case %d: ", ++cas);
		int l = 1, r = 500000000;
		while(l < r-1) {
			int mid = (l+r)/2;
//			printf("get0(%d) = %d\n", mid, get0(mid));
//			printf("l = %d r = %d\n", l, r); getchar();
			if(get0(mid) <= n) l = mid;
			else r = mid-1;
		}
		
		if(get0(l) == n) {
			for(int i = l;;i--) if(get0(i) != n) {
				printf("%d\n", i+1);
				break;
			}
		}
		else puts("impossible");
	}
}