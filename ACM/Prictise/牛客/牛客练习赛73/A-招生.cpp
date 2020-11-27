#include <bits/stdc++.h>
using namespace std;

int n, m;
double p;
struct node {
	double gk, xc;
} stu[100005];

bool cmp(node a, node b) {
	return 0.85*a.gk+0.15*a.xc > 0.85*b.gk+0.15*b.xc;
}

int main() {
	scanf("%d %d %lf", &n, &m, &p);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &stu[i].gk, &stu[i].xc);
	}
	sort(stu+1, stu+1+n, cmp);
	double nowa = stu[m].gk, nowb = stu[m].xc;
	
	long long x = ceil((nowa*0.85+nowb*0.15-p*0.15)/0.85);
	printf("%lld\n", max(1LL*0, x));
}