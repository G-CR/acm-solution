#include <bits/stdc++.h>
using namespace std;

int _, n, x;
double sum;

int main() {
	scanf("%d", &_);
	while(_--) {
		sum = 0;
		scanf("%d", &n);
		int Max = -1, Min = 1e9;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			sum += (double)x;
			Max = max(Max, x); Min = min(Min, x);
		}
		
		printf("MAX:%d\nMIN:%d\nAVG:%.2lf\n", Max, Min, sum/n);
	}
}