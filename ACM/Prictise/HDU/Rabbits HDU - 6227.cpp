#include <bits/stdc++.h>
using namespace std;

int t, n, x;
vector <int> vc;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		vc.clear();
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			vc.push_back(x);
		}
		sort(vc.begin(), vc.end());
		int sum = 0;
		int len = vc.size();
		for(int i = 1;i < len; i++) {
			int cha = vc[i]-vc[i-1]-1;
			sum += cha;
		}
		int p = vc[1]-vc[0]-1;
		int q = vc[len-1]-vc[len-2]-1;
		printf("%d\n", sum-min(p, q));
	}
}