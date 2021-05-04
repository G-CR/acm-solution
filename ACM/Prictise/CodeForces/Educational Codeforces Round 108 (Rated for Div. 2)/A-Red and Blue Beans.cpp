#include <bits/stdc++.h>
using namespace std;

int _;
int r, b, d;

int main() {
	scanf("%d", &_); while(_--) {
		scanf("%d %d %d", &r, &b, &d);
		int mi = min(r, b);
		r -= mi; b -= mi;
		int num = r?r:b;
		int ans = ceil(1.0 * num / mi);
		if(ans > d) puts("NO");
		else puts("YES");
	}
}