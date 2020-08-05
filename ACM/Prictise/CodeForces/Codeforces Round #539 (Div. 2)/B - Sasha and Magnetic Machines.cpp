#include <bits/stdc++.h>
using namespace std;

int n,sum;
int a[50004];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a+1, a+1+n);
	
	sum -= a[1];
	int ans = 202,ans1,ans2,pos;
	for(int i = 2;i <= n; i++) {
		for(int j = a[i];j >= 1; j--) {
			if(a[i] % j == 0) {
				if((a[1]*j + a[i]/j)-(a[1]+a[i]) < ans) {
					ans = (a[1]*j + a[i]/j)-(a[1] + a[i]);
					pos = i;
					ans1 = a[1]*j; ans2 = a[i]/j;
				}
			}
		}
	}
	a[1] = ans1; sum -= a[pos];
	a[pos] = ans2;
	sum += (a[1]+a[pos]);
	printf("%d\n", sum);
}