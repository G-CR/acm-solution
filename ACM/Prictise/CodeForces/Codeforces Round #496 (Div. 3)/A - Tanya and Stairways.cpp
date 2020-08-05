#include <bits/stdc++.h>
using namespace std;

int n, a[1005];
vector <int> vc;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int cnt = 1;
	for(int i = 1;i <= n; i++) {
		if(a[i+1] == 1) {
			vc.push_back(a[i]);
			cnt++;
		}
	}
	vc.push_back(a[n]);
	printf("%d\n", cnt);
	for(int i = 0;i < vc.size(); i++) {
		printf("%d ", vc[i]);
	}
	puts("");
}