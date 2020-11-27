#include <bits/stdc++.h>
using namespace std;

double h, l, H, L;

int main() {
	cin >> h >> l >> H >> L;
	if(h/l <= H/L) {
		printf("%.8lf\n", h*h*L/H/2);
	}
	else {
		printf("%.12lf\n", (2*h*l*L-l*l*H)/(2*L));
	}
	
}