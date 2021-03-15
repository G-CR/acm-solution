#include <bits/stdc++.h>
using namespace std;

int f(int a) {
	int res = 0;
	while(a) {
		int t = a % 10;
		if(t == 2) res++;
		a /= 10;
	}
	return res;
}

int cal(int l, int r) {
	int ans = 0;
	for(int i = l;i <= r; i++) {
		ans += f(i);
	}
	return ans;
}

int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	printf("%d\n", cal(l, r));
}