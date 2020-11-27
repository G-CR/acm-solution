#include <bits/stdc++.h>
using namespace std;

int n, k;
bool a[1003], b[1003];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1;i <= n; i++) {
		scanf("%d", &b[i]);
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] == b[i]) ans++;
		else if(k){
			k--;
			ans++;
		}
	}
	
	printf("%d\n", ans-k);
}