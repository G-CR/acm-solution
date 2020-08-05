#include <bits/stdc++.h>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};
int num[2002];
int n, ans;

int main() {
	scanf("%d", &n);
	num[0] = 6;
	for(int i = 1;i <= 2000; i++) {
		int j = i;
		while(j) {
			num[i] += a[j%10];
			j /= 10;
		}
	}
	
	for(int i = 0;i <= 1000; i++) {
		for(int j = 0;j <= 1000; j++) {
			if(num[i]+num[j]+num[i+j]+4 == n) {
//				printf("%d+%d=%d\n", i,j,i+j);
				ans++;
			}
				
		}
	}
	
	printf("%d\n", ans);
}