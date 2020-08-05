#include <bits/stdc++.h>
using namespace std;

int t;
float a, b, c, d, k;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%f %f %f %f %f", &a, &b, &c, &d, &k);
		int t1 = ceil(a/c);
		int t2 = ceil(b/d);
		if(t1 + t2 <= k) {
			printf("%d %d\n", t1, (int)k-t1);
		} else {
			puts("-1");
		}
	}
}