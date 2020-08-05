#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
double n, r;
int p, q;
int a[5000];

int main() {
	scanf("%lf %lf %d %d", &n, &r, &p, &q);
	double l = 2.0*r*sin(pi/n);
	
	for(int i = 1;i <= n; i++) a[i] = i;
	for(int i = n+1; i <= 2*n; i++) a[i] = a[i-(int)n];
	int p1 = 0, q1 = 0, p2 = 0, q2 = 0;
	for(int i = 1;i <= 2*n; i++) {
		if(!p1 && a[i] == p) {
			p1 = i;
		}
		else if(a[i] == p) p2 = i;
		
		if(!q1 && a[i] == q) {
			q1 = i;
		}
		else if(a[i] == q) q2 = i;
	}
//	printf("p1 = %d q1 = %d p2 = %d q2 = %d\n", p1, q1, p2, q2);
//	printf("%d %d %d %d\n", abs(p1-q1), abs(p1-q2), abs(p2-q1), abs(p2-q2));
	int t = abs(p1-q1);
	t = min(t, abs(p1-q2));
	t = min(t, abs(p2-q1));
	t = min(t, abs(p2-q1));
	printf("%lf\n", l*t);
}