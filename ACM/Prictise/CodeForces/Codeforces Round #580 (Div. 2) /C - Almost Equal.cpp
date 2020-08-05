#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

int main() {
	scanf("%d", &n);
	if(!(n%2)) return puts("NO"), 0;
	puts("YES");
	int j = 1;
	for(int i = 1;i <= n; i+=2) {
		a[i] = j++;
		a[i+n] = j++;
		if(i+n+1 > 2*n) break;
		a[i+n+1] = j++;
		a[i+1] = j++;
	}
	for(int i = 1;i <= 2*n; i++) printf("%d ",a[i]);
}