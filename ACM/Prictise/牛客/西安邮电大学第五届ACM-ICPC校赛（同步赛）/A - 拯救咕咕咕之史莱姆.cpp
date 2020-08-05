#include <bits/stdc++.h>
using namespace std;

long long big[100], small[100], hp;

void init() {
	big[1] = 1; small[1] = 0;
	big[2] = 1; small[2] = 2;
	big[3] = 1; small[3] = 4;
	big[4] = 1; small[4] = 6;
	for(int i = 5;i <= 100; i++) {
		big[i] = big[i-1]+(small[i-3]-small[i-4]);
		small[i] = small[i-1] - (big[i]-big[i-1]) + big[i-1]*2;
	}
}

int main() {
	init();
	long long sum = 0;
	for(int i = 1;i <= 5; i++) {
		sum += (big[i]+small[i]) * 3;
	}
	while(~scanf("%lld", &hp) && hp) {
		if(hp <= sum) puts("AOLIGEI!");
		else puts("DAAAAAMN!");
	}
}