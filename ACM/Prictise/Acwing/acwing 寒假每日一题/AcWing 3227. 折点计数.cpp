#include <bits/stdc++.h>
using namespace std;

int n;
int a[1003];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int z = 0;
	if(a[2] > a[1]) z = 1;
	else z = -1;
	
	int ans = 0;
	
	for(int i = 3;i <= n; i++) {
		if(a[i] > a[i-1] && z == -1) {
			ans++;
			z = -z;
		}
		else if(a[i] < a[i-1] && z == 1) {
			ans++;
			z = -z;
		}
	}
	
	printf("%d\n", ans);
}