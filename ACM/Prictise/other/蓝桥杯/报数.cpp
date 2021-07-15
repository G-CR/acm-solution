#include <bits/stdc++.h>
using namespace std;

int n;
deque <int> q;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	
	bool ok = 1;
	while(q.size() > 1) {
		int now = q.front(); q.pop_front();
		if(ok) q.push_back(now);
		ok = !ok;
	}
	
	printf("%d\n", q.front());
}