#include <bits/stdc++.h>
using namespace std;

int n,v;

int main() {
	scanf("%d %d", &n, &v);
	int ans = v,i = 2,t = n-1;
	if(v >= n-1) return printf("%d\n", n-1),0;
	while(t > 0) {
		if(t <= v) {
			t--; continue;
		}
		ans += i;
		t--; i++;
	}
	printf("%d\n", ans);
}