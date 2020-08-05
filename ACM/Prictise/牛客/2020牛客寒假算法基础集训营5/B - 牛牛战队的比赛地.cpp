#include <bits/stdc++.h>
using namespace std;
const double ps = 1e-6;
int n;
double x[100005], y[100005];

double dist(double pos) {
	double res = -1;
	for(int i = 1;i <= n; i++) {
		res = max(res, sqrt((x[i]-pos)*(x[i]-pos) + y[i]*y[i]));
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	double head = -10000, tail = 10000;
	while(head+ps < tail) {
		double len = (tail-head)/3;
		double lmid = head+len;
		double rmid = tail-len;
		if(dist(lmid) > dist(rmid)) head = lmid;
		else tail = rmid;
	}
	printf("%lf\n", dist(tail));
}