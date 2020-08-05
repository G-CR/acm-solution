#include <bits/stdc++.h>
using namespace std;

double sn, n, k, i;

int main() {
	cin >> k;
	for(i = 1;;i++) {
		sn += 1/i;
		if(sn > k) break;
	}
	printf("%.0lf\n", i);
}