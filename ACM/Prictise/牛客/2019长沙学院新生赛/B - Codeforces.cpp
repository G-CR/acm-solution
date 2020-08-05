#include<bits/stdc++.h>
using namespace std;
 
int n;
int a[300005];
 
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= 3*n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+3*n);
	 
	int ans = -1;
	for(int i = 1;i <= 3*n; i+=3) {
		ans = max(ans, a[i+2]-a[i]);
	}
	 
	printf("%d\n", ans);
}