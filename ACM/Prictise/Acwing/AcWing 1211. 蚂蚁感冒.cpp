#include <bits/stdc++.h>
using namespace std;

int n, a[55];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int num = 1, r = 0, l = 0;
	for(int i = 2; i <= n; i++) {
		if(abs(a[i]) < abs(a[1]) && a[i] > 0) r++;
		else if(abs(a[i]) > abs(a[1]) && a[i] < 0) l++;
	}
	if((a[1] < 0 && r == 0) || (a[1] > 0 && l == 0)) puts("1");
	else printf("%d\n", l + r + 1);
}