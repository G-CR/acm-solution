#include <bits/stdc++.h>
using namespace std;

int n, Q;
double poi, npoi, np, mpoi, mp, fpoi, fp, sum;
vector<double> ans, jpoi;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %lf %lf %lf %lf %lf %lf %lf", &Q, &poi, &npoi, &np, &mpoi, &mp, &fpoi, &fp);
		if(Q == 2) continue;
		sum += poi;
		double t = npoi*np + mpoi*mp + fpoi*fp;
		int tt = (int)(t+0.5);
		jpoi.push_back(poi);
		ans.push_back((double)tt);
	}
	double fans = 0;
	for(int i = 0;i < ans.size(); i++) {
		fans += (ans[i]*(jpoi[i]/sum));
	}
	printf("%.2lf\n", fans);
}