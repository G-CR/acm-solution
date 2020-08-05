#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1;i <= n; i++) {
		int ans = 0;
		for(int j = 1;j < i; j++) {
			if(a[j] < a[i]) ans++;
		}
		printf("%d ", ans);
	}
}