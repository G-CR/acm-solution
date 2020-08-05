#include <bits/stdc++.h>
using namespace std;

int n, s, a, b, p, q;
vector <int> vc;

int main() {
	scanf("%d %d %d %d", &n, &s, &a, &b);
	int hei = a+b;
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &p, &q);
		if(hei >= p) {
			vc.push_back(q);
		}
	}
	sort(vc.begin(), vc.end());
	
	int ans = 0;
	for(int i = 0;i < vc.size(); i++) {
		if(s >= vc[i]) {
			s -= vc[i];
			ans++;
		}
		else break;
	}
	
	printf("%d\n", ans);
}