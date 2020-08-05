#include <bits/stdc++.h>
using namespace std;

int q, n, minn;
int t[15];

void dfs(int p,int sum) {
	if(p == 12){
		if(sum < n){
			return;
		}
		else{
			minn = min(minn, sum);
			return;
		}
	}
	
	dfs(p+1, sum+t[p]);
	dfs(p+1, sum);
}

int main() {
	scanf("%d", &q);
	int k = 1;
	for(int i = 1;i <= 12; i++) {
		t[i] = k;
		k *= 3;
	}
	while(q--) {
		minn=100000000;
		scanf("%d", &n);
		dfs(0,0);
		printf("%d\n", minn);
	}
}