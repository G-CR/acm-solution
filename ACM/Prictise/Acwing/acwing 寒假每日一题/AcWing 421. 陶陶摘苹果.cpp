#include <bits/stdc++.h>
using namespace std;

int a[11], p;

int main() {
	for(int i = 1;i <= 10; i++) scanf("%d", &a[i]);
	scanf("%d", &p); p += 30;
	
	int ans = 0;
	for(int i = 1;i <= 10; i++) {
		if(p >= a[i]) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
}