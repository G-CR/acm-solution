#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[100005];
bool fine[100005];
vector <int> vc;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		vc.push_back(a[i]);
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		while(fine[*vc.begin()]) vc.erase(vc.begin());
		
		if(x != *vc.begin()) {
			ans++;
			fine[x] = 1;
		}
		else {
			vc.erase(vc.begin());
		}
	}
	printf("%d\n", ans);
}