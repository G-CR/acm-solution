#include <bits/stdc++.h>
using namespace std;

double x[3], y[3], l[3];

int main() {
	for(int i = 0;i < 3; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}
	
	double C = 0;
	vector <double> l;
	for(int i = 0;i < 3; i++) {
		l.push_back(sqrt((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3]) + (y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3])));
		C += l[l.size()-1];
	}
	C /= 2.0;
	printf("%.3lf\n", sqrt(C*(C-l[0])*(C-l[1])*(C-l[2])));
}