#include <bits/stdc++.h>
using namespace std;

struct Node1{
	int a,b;
}sst[10];

struct Node2{
	int pos;
	char key;
}ans[10];

bool ok[10],fin,sb;
int n,k = 1;

void dfs(int pre,int t) {
	int i;
	if(t == n-1) {
		sb = 1;
		return;
	}
	for(i = 1;i <= n; i++) {
		if(ok[i]) continue;
		int p = pre;
		if(sst[i].a == pre) {
			ok[i] = 1;
			pre = sst[i].b;
			ans[k].pos = i; ans[k++].key = 'a';
			dfs(pre,t+1);
			if(sb) return;
			ok[i] = 0; k--; pre = p;
		}
		if(sst[i].b == pre) {
			ok[i] = 1;
			pre = sst[i].a;
			ans[k].pos = i; ans[k++].key = 'b';
			dfs(pre,t+1);
			if(sb) return;
			ok[i] = 0; k--; pre = p;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &sst[i].a, &sst[i].b);
	}
	int pre;
	for(int i = 1;i <= n; i++) {
		fin = 1;k = 1;
		memset(ok,0,sizeof(ok));
		ans[k].pos = i; ans[k++].key = 'a';
		pre = sst[i].b; ok[i] = 1; sb = 0;
		dfs(pre,0);
		
		for(int j = 1;j <= n; j++){
			if(!ok[j]) fin = 0;
		}
		if(fin){
			for(int j = 1;j <= n; j++){
				printf("%d %c\n", ans[j].pos, ans[j].key);
			}
			return 0;
		}
		
		else if(!fin) {
			memset(ok,0,sizeof(ok));k = 1;fin=1;
			ans[k].pos = i; ans[k++].key = 'b';
			pre = sst[i].a; ok[i] = 1; sb = 0;
			dfs(pre,0);
		}
		for(int j = 1;j <= n; j++) if(!ok[j]) fin = 0;
		if(fin){
			for(int j = 1;j <= n; j++){
				printf("%d %c\n", ans[j].pos, ans[j].key);
			}
			return 0;
		}
	}
}