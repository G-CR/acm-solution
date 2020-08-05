#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	long long k, b;
}l[102];
struct poi {
	double x, y;
	poi(double a, double b) {x = a;y = b;}
};

vector <poi> v;

bool check(double x, double y, double xx, double yy) {
	if(abs(x-xx) < 0.000000000000015 && abs(y-yy) < 0.000000000000015) return 1;
	return 0;
}

bool find(double x, double y) {
	int len = v.size();
	bool ok = 0;
	for(int i = 0;i < len; i++) {
		poi t = v[i];
		if(check(x,y,t.x,t.y)) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld", &l[i].k, &l[i].b);
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = i+1;j <= n; j++) {
			if(l[i].k == l[j].k) continue;
			double x = ((double)l[j].b-(double)l[i].b)/((double)l[i].k-(double)l[j].k);
			double y = (double)l[i].k * x + (double)l[i].b;
			if(!find(x, y)) v.push_back(poi(x, y));
		}
	}
	
	if(v.empty()) puts("No Fire Point.");
	else printf("%d\n", (int)v.size());
}