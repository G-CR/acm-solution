#include <bits/stdc++.h>
using namespace std;

int x, n;
int a[8];
int main() {
	scanf("%d %d", &x, &n);
	for(int i = 1;i <= 5; i++) a[i] = 250;
	a[6] = a[7] = 0;
	
	int ans = 0, t = x;
	while(n--) {
		ans += a[t];
		t++;
		if(t == 8) t = 1;
	}
	
	printf("%d\n", ans);
}