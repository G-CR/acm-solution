#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int h,pos;
}sst[100005];
int pre[100005];
stack<node> sta;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &sst[i].h);
		sst[i].pos = i;
		pre[i] = min(sst[i].h,n-i);
		while(!sta.empty() && sst[i].h > sta.top().h) {
			pre[sta.top().pos] = i-sta.top().pos-1;
			sta.pop();
		}
		sta.push(sst[i]);
	}
	for(int i = 1;i <= n; i++) {
		printf("%d ",pre[i]);
	}
}