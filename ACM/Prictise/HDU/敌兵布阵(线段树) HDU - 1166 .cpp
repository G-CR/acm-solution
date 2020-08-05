#include <bits/stdc++.h>
using namespace std;

int T,N,i,j,ans;
string s;

struct node {
	int l,r,sum;
}tree[200005];

void build(int k, int left, int right) {
	tree[k].l = left; tree[k].r = right;
	if(left == right) {
		scanf("%d", &tree[k].sum);
		return;
	}
	int mid = (left+right) / 2;
	build(2*k, left, mid);
	build(2*k+1, mid+1, right);
	
	tree[k].sum = tree[2*k].sum + tree[2*k+1].sum;
}


void change_point(int k) {
	if(tree[k].l == tree[k].r) {
		if(s == "Add") tree[k].sum += j;
		else if(s == "Sub") tree[k].sum -= j;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(i <= mid) change_point(2*k);
	else change_point(2*k+1);
	
	tree[k].sum = tree[2*k].sum + tree[2*k+1].sum;
}

void ask_interval(int k) {
	if(i <= tree[k].l && tree[k].r <= j) {
		ans += tree[k].sum;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(i <= mid) ask_interval(2*k);
	if(j > mid) ask_interval(2*k+1);
}

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%d", &N);
		build(1, 1, N);
		printf("Case %d:\n",p);
		while(1) {
			cin >> s;
//			cout << s << endl;
			if(s == "End") break;
			scanf("%d %d", &i, &j);
//			cout << "i = " << i << " j = " << j << endl;
			if(s == "Query") {
				ask_interval(1);
				printf("%d\n", ans);
				ans = 0;
			}
			else {
				change_point(1);
			}
		}
	}
	return 0;
}