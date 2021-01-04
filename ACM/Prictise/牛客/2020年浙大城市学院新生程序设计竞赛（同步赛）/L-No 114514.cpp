#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

bool check(int l, int r) {
	string s = "";
	for(int i = l;i <= r; i++) {
		s += a[i]+'0';
	}
	return s == "114514";
}


int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(n < 6) for(int i = 1;i <= n; i++) printf("%d", a[i]);
	else {
		int l = 1, r = 6;
		while(r <= n) {
			if(check(l, r)) {
				a[r] = 5;
				l += 6; r += 6;
			}
			else {
				l++; r++;
			}
		}
		for(int i = 1;i <= n; i++) printf("%d ", a[i]);
	}
}