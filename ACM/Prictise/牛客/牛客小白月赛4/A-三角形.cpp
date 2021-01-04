#include <bits/stdc++.h>
using namespace std;

int n, q;
int ans[3];
struct node {
	long long len;
	int id;
} l[100005];

map <int, long long> vis, zh;

bool cmp(node a, node b) {
	return a.len > b.len;
}

bool can(int i, int j, int k) {
	return l[i].len < l[j].len + l[k].len;
}

int inpos(int x) {
	for(int i = 0;i < 3; i++) if(zh[x] == ans[i]) return ans[i];
	return -1;
}

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &l[i].len);
		l[i].id = i;
	}
	sort(l+1, l+1+n, cmp);
	for(int i = 1;i <= n; i++) {zh[l[i].id] = i;}
	
	int pos = -1;
	for(int i = 1;i <= n-2; i++) {
		if(can(i, i+1, i+2)) {
			pos = i;
			vis[0] = l[i].len + l[i+1].len + l[i+2].len;
			break;
		}
	}
	
	if(pos > 0) {
		ans[0] = pos; ans[1] = pos+1; ans[2] = pos+2;
	}
	
	vis[l[pos].id] = -1;
	for(int i = pos+1;i <= n-2; i++) {
		if(can(i, i+1, i+2)) {
			vis[l[pos].id] = l[i].len + l[i+1].len + l[i+2].len;
			break;
		}
	}
	
	
	if(pos+3 <= n && can(pos, pos+2, pos+3)) vis[l[pos+1].id] = l[pos].len + l[pos+2].len + l[pos+3].len;
	else {
		vis[l[pos+1].id] = -1;
		for(int i = pos+2;i <= n-2; i++) {
			if(can(i, i+1, i+2)) {
				vis[l[pos+1].id] = l[i].len + l[i+1].len + l[i+2].len;
				break;
			}
		}
	}
	
	if(pos+3 <= n && can(pos, pos+1, pos+3)) vis[l[pos+2].id] = l[pos].len + l[pos+1].len + l[pos+3].len;
	else if(pos+4 <= n && can(pos+1, pos+3, pos+4)) vis[l[pos+2].id] = l[pos+1].len + l[pos+3].len + l[pos+4].len;
	else {
		vis[l[pos+2].id] = -1;
		for(int i = pos+3;i <= n-2; i++) {
			if(can(i, i+1, i+2)) {
				vis[l[pos+2].id] = l[i].len + l[i+1].len + l[i+2].len;
				break;
			}
		}
	}
	
	int x;
	while(q--) {
		scanf("%d", &x);
		if(pos == -1) {puts("-1"); continue;}
		int t = inpos(x);
		if(t == -1) printf("%lld\n", vis[0]);
		else printf("%lld\n", vis[l[t].id]);
	}
}