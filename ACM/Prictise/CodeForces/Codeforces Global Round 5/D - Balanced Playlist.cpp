#include <bits/stdc++.h>
using namespace std;

int n, a[300005], ans[100005];
multiset <int> mt;

int main() {
	scanf("%d", &n);
	int n3 = n*3;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		a[i+2*n] = a[i+n] = a[i];
	}
	
	int r = 1;
	for(int i = 1;i <= n; i++) {
		while(r <= n3) {
			if(!mt.empty()) {
				int p = *mt.rbegin();
				if(a[r]*2 < p) break;
			}
			mt.insert(a[r]); r++;
		}
		ans[i] = r <= n3 ? r-i : -1;
		mt.erase(mt.find(a[i]));
	}
	
	for(int i = 1;i <= n; i++) printf("%d ", ans[i]);
	puts("");
}