#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;

int n, m;
long long ma[maxn<<2];
int num[maxn<<2];

void build(int l, int r, int k) {
	if(l == r) {
		scanf("%lld", &ma[k]);
		num[k] = 1;
		return;
	}
	int mid = (l+r) >> 1;
	build(l, mid, 2*k);
	build(mid+1, r, 2*k+1);
	ma[k] = max(ma[2*k], ma[2*k+1]);
	
	if(ma[2*k] == ma[2*k+1]) num[k] = num[2*k] + num[2*k+1];
	else if(ma[2*k] > ma[2*k+1]) num[k] = num[2*k];
	else if(ma[2*k] < ma[2*k+1]) num[k] = num[2*k+1];
}

void up(int pos, int val, int l, int r, int k) {
	if(l == r) {
		ma[k] = val;
		return;
	}
	int mid = (l+r) >> 1;
	if(pos <= mid) up(pos, val, l, mid, 2*k);
	else up(pos, val, mid+1, r, 2*k+1);
	ma[k] = max(ma[2*k], ma[2*k+1]);
	
	if(ma[2*k] == ma[2*k+1]) num[k] = num[2*k] + num[2*k+1];
	else if(ma[2*k] > ma[2*k+1]) num[k] = num[2*k];
	else if(ma[2*k] < ma[2*k+1]) num[k] = num[2*k+1];
}

pair<long long, int> qu(int L, int R, int l, int r, int k) {
	if(L <= l && r <= R) {
		return {ma[k], num[k]};
	}
	
	int mid = (l+r)>>1;
	pair <long long, int> t1 , t2;
	if(L <= mid) t1 = qu(L, R, l, mid, 2*k);
	if(R > mid) t2 = qu(L, R, mid+1, r, 2*k+1);
	
	if(t1.first == t2.first) return {t1.first, t1.second+t2.second};
	else if(t1.first > t2.first) return t1;
	else return t2;
}

int main() {
	scanf("%d %d", &n, &m);
	build(1, n, 1);
	while(m--) {
		string cas;
		int x, y;
		cin >> cas;
		scanf("%d %d", &x, &y);
		if(cas == "Ask") {
			auto res = qu(x, y, 1, n, 1);
			printf("%lld %d\n", res.first, res.second);
		}
		else if(cas == "Change") {
			up(x, y, 1, n, 1);
		}
	}
}