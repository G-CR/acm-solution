#include <bits/stdc++.h>
using namespace std;

long long n, ansz, ansf, ans0;
int a[200005];

int main() {
	scanf("%lld", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > 0) a[i] = 1;
		if(a[i] < 0) a[i] = -1;
	}
	
	int t1 = 0, t2 = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] == 1) {
			t1++;
			ansz += t1;
			ansf += t2;
		}
		else if(a[i] == -1) {
			swap(t1, t2);
			t2++;
			ansz += t1;
			ansf += t2;
		}
		else {
			t1 = t2 = 0;
		}
	}
	long long tot = (n+1)*n/2;
	ans0 = tot - ansz - ansf;
	printf("%lld %lld %lld\n", ansf, ans0, ansz);
}