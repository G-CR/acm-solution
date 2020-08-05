#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, r, len;
	node(int left, int right, int length) {l=left;r=right;len=length;}
	bool operator < (const node&o) const {
		if(len == o.len) return l > o.l;
		return len < o.len;
	}
};

priority_queue <node> q;
int _, n, a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) a[i] = 0;
		q.push(node(1,n,n));
		int num = 0;
		while(!q.empty()) {
			node t = q.top(); q.pop();
			int mid = (t.l+t.r)/2;
			a[mid] = ++num;
			if(mid-1-t.l+1) q.push(node(t.l, mid-1, mid-1-t.l+1));
			if(t.r-(mid+1)+1) q.push(node(mid+1, t.r, t.r-(mid+1)+1));
		}
		for(int i = 1;i <= n; i++) printf("%d ", a[i]);
		puts("");
	}
}