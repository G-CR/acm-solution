#include <bits/stdc++.h>
using namespace std;

int _, n;
string s;

int go(int l, int r, char ch){
	int num = 0;
	for(int i = l;i <= r; i++){
		if(s[i-1] != ch){
			num++;
		}
	}
	return num;
}
int dfs(int l, int r, char ch) {
	if(l == r) return (s[l-1] != ch);
	int mid=(l+r)/2;
	return min(dfs(l, mid, ch+1) + go(mid+1, r, ch),dfs(mid+1, r, ch+1)+go(l, mid, ch));
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> s;
		printf("%d\n", dfs(1,n,'a'));
	}
}