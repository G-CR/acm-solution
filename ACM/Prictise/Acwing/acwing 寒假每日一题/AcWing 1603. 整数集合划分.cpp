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
	int mid = n/2;
	int sum1 = 0;
	for(int i = 1; i <= mid; i++) {
		sum1 += a[i];
	}
	int sum2 = 0;
	for(int i = mid+1; i <= n; i++) {
		sum2 += a[i];
	}
	
	if(n%2) printf("1 ");
	else printf("0 ");
	
	printf("%d\n", sum2-sum1);
}