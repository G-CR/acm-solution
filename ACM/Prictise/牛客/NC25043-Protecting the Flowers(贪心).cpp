#include <bits/stdc++.h>
using namespace std;

int n;
long long sum[100005];
struct node {
	double t, d;
	double quan;
} cow[100005];

bool cmp(node a, node b) {
	return a.quan < b.quan;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &cow[i].t, &cow[i].d);
		cow[i].quan = cow[i].t/cow[i].d;
	}
	
	sort(cow+1, cow+1+n, cmp);
	for(int i = 1;i <= n; i++) {
		sum[i] += sum[i-1]+cow[i].d;
	}
	
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += (sum[n]-sum[i])*cow[i].t*2;
	}
	
	printf("%lld\n", ans);
}