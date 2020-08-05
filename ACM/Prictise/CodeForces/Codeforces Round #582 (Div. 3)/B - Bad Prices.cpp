#include <bits/stdc++.h>
using namespace std;

int t,n,a[150005],ans;
stack<int> sst;
int main() {
	scanf("%d", &t);
	while(t--) {
		while(!sst.empty()) sst.pop();
		scanf("%d", &n);
		ans = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = n;i >= 1; i--) {
			if(!sst.empty()) {
				if(sst.top() < a[i]) ans++;
				else sst.push(a[i]);
				continue;
			}
			sst.push(a[i]);
		}
		printf("%d\n", ans);
	}
}