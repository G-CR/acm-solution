#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	
	int Min = min(a[n]-a[1],min(a[n]-a[2],a[n-1]-a[1]));
	printf("%d\n", Min);
}