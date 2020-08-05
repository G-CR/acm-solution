#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q;
priority_queue <int, vector<int> > p;
int _, num, n, a[10000];

int main() {
	scanf("%d", &_);
	while(_--) {
		int cnt = 0;
		scanf("%d %d", &num, &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		printf("%d %d\n", num, n/2+1);
		while(!q.empty()) q.pop(); 
		while(!p.empty()) p.pop();
		for(int i = 1;i <= n; i++) {
			if((q.empty() && p.empty()) || a[i] >= q.top()) q.push(a[i]);
			else p.push(a[i]);
			while((int)q.size()-(int)p.size() > 1) {int t = q.top(); q.pop(); p.push(t);}
			while((int)p.size()-(int)q.size() > 1) {int t = p.top(); p.pop(); q.push(t);}
			if(i&1) {
				if(q.size() > p.size()) printf("%d ", q.top());
				else printf("%d ", p.top());
			}
			if(i%20 == 0) puts("");
		}
		if(_) puts("");
	}
}