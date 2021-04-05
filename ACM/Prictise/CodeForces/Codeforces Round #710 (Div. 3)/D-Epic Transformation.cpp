#include <bits/stdc++.h>
using namespace std;

int _, n;
int x;
map <int, int> mp;
int cnt[200005];

priority_queue<int> q;

int main() {
	scanf("%d", &_);
	while(_--) {
		mp.clear();
		scanf("%d", &n);
		int num = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			if(!mp[x]) mp[x] = ++num;
			cnt[mp[x]]++;
		}
		
		for(int i = 1; i <= num; i++) {
			q.push(cnt[i]);
		}
		
		while(q.size() >= 2) {
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
//			printf("%d %d\n", a, b);
			a--; if(a) q.push(a);
			b--; if(b) q.push(b);
		}
		if(!q.empty()) printf("%d\n", q.top());
		else puts("0");
		
		while(!q.empty()) q.pop();
		for(int i = 1; i <= num; i++) {
			cnt[i] = 0;
		}
	}
}