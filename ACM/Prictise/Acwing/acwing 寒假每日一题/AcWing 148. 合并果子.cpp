#include <bits/stdc++.h>
using namespace std;

int n;
int a[10004];
priority_queue<int, vector <int>, greater<int> > q;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		q.push(a[i]);
	}
	
	int ans = 0;
	while(!q.empty()) {
		if(q.size() == 1) break;
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		q.push(a+b);
		ans += a + b;
	}
	
	printf("%d\n", ans);
}