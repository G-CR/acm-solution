#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, ans[200005];
struct node{
	int pos;
	ll a;
}sst[200005];
ll sum;

bool cmp(node a, node b) {
	if(a.a == b.a) return a.pos < b.pos;
	return a.a < b.a;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &sst[i].a);
		sst[i].pos = i;
		sum += sst[i].a;
	}
	sort(sst+1, sst+1+n, cmp);
	
	int j = 0;
	for(int i = 1;i <= n; i++) {
		if(i == n) {
			if(sum - sst[i].a == 2*sst[n-1].a) {
				ans[++j] = sst[i].pos;
			}
		}
		else if(sum - sst[i].a  == 2*sst[n].a) {
			ans[++j] = sst[i].pos;
		}
	}
	printf("%d\n", j);
	for(int i = 1;i <= j; i++) {
		printf("%d ", ans[i]);
	}
}