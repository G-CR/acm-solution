#include <bits/stdc++.h>
using namespace std;

long long num[62][10];
int n;

int main() {
	num[1][1] = 0; num[1][2] = 1; num[1][3] = 0; num[1][4] = 0; num[1][5] = 0; num[1][6] = 0;
	num[2][1] = 1; num[2][2] = 1; num[2][3] = 0; num[2][4] = 1; num[2][5] = 0; num[2][6] = 0;
	
	scanf("%d", &n);
	for(int i = 3;i <= n; i++) {
		if(i%2) {
			 num[i][1] = num[i-1][1];
			num[i][2] = num[i-1][5]*2 + i/2 + (i+1)/2;
			num[i][3] = num[i-1][5]*2 + i/2;
			 num[i][4] = num[i-1][4];
			 num[i][5] = num[i-1][5];
			num[i][6] = num[i-1][5]*2 + i/2;
		}
		else {
			num[i][1] = num[i-1][6]*2 + i/2;
			num[i][2] = num[i-1][2];
			num[i][3] = num[i-1][3];
			num[i][4] = num[i-1][6]*2 + i/2;
			num[i][5] = num[i-1][6]*2;
			num[i][6] = num[i-1][6];
		}
	}
	long long sum = (long long)(pow(2,n))-1;
	printf("A->B:%lld\n", num[n][1]);
	printf("A->C:%lld\n", num[n][2]);
	printf("B->A:%lld\n", num[n][3]);
	printf("B->C:%lld\n", num[n][4]);
	printf("C->A:%lld\n", num[n][5]);
	printf("C->B:%lld\n", num[n][6]);
	printf("SUM:%lld\n", sum);
}