#include <bits/stdc++.h>
using namespace std;

int _, n;
vector <pair<int, int> > ans;

struct node {
	long long pz;
	int id;
} a[5005];
vector <node> v;

bool cmp1(node a, node b) {
	if(a.pz == b.pz) return a.id < b.id;
	return a.pz < b.pz;
}

bool cmp2(node a, node b) {
	if(a.pz == b.pz) return a.id > b.id;
	return a.pz > b.pz;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ans.clear();
		v.clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i].pz);
			a[i].id = i;
		}
		sort(a+1, a+1+n, cmp1);
		v.push_back(a[1]);
		sort(a+1, a+1+n, cmp2);
		bool fin = 1;
		for(int i = 1;i < n; i++) {
			bool ok = 0;
			for(node j: v) {
				if(a[i].pz != j.pz) {
					ok = 1;
					v.push_back(a[i]);
					ans.push_back({j.id, a[i].id});
				}
				if(ok) break;
			}
			if(!ok) {
				fin = 0;
				break;
			}
		}
		
		if(fin) {
			puts("YES");
			for(auto i: ans) {
				printf("%d %d\n", i.first, i.second);
			}
		}
		else {
			puts("NO");
		}
	}
}