#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[200005];
priority_queue <int, vector<int>, greater<int> > q;
priority_queue<int> Q;

bool cmp(int a, int b) {return a > b;}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i = 1;i <= min(n, k-1); i++) {
		Q.push(a[i]);
	}
	for(int i = k;i <= n; i++) {
		q.push(a[i]);
	}
	
	while (m--) {
		int cas; scanf("%d", &cas);
		if(cas == 1) {
			int now; scanf("%d", &now);
			if(now < Q.top() || Q.size() < k-1) Q.push(now);
			else q.push(now);
			while(Q.size() > k-1) {
				q.push(Q.top());
				Q.pop();
			}
		}
		else {
			if(q.empty()) {puts("-1"); continue;}
			printf("%d\n", q.top());
		}
	}
}