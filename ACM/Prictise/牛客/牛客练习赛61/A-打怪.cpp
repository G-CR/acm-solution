#include <bits/stdc++.h>
using namespace std;

int _;
int h, a, H, A;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d %d", &h, &a, &H, &A);
		if(A == 0 || a >= H) puts("-1");
		else if(a == 0) puts("0");
		else {
			int t = H/a;
			if(H%a) t++;
			int ans = h/((t-1)*A);
			if(h%((t-1)*A) == 0) ans--;
			printf("%d\n", ans);
		}
	}
}