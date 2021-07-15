#include <bits/stdc++.h>
#define pdd pair <double, double>
using namespace std;

int n;
double ans = 1e18;
pdd p[105], av;

double getp(double l, double r) {
	return (double)rand() / RAND_MAX * (r-l) + l;
}

double cal(pdd now) {
	double res = 0;
	for(int i = 1; i <= n; i++) {
		res += sqrt((now.first-p[i].first)*(now.first-p[i].first)+(now.second-p[i].second)*(now.second-p[i].second));
	}
	return res;
}

void sa() {
	pdd cur = av;
	double curd = cal(av);
	for(double T = 5000; T > 1e-14; T *= 0.996) {
		pdd t = {getp(cur.first-T, cur.first+T), getp(cur.second-T, cur.first+T)};
		double td = cal(t);
		if(td < curd) {
			cur = t; curd = td;
			ans = min(ans, curd);
		}
		else if(exp((curd-td)/T) > getp(0, 1)) {
			cur = t; curd = td;
		}
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &p[i].first, &p[i].second);
		av.first += p[i].first;
		av.second += p[i].second;
	}
	av.first /= n; av.second /= n;
	
	int num = 100;
	while(num--) {
		sa();
	}
	
	printf("%.0lf\n", ans);
}