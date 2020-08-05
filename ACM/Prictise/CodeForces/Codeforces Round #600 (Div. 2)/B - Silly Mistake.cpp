#include <bits/stdc++.h>
using namespace std;

int n, a[100005], ans[100005];
map <int, bool> mp;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int sum = 0, num = 0, j = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] > 0) {
			if(mp[a[i]]) return puts("-1"), 0;
			mp[a[i]] = 1;
		}
		else {
			if(!mp[-a[i]] || mp[a[i]]) return puts("-1"), 0;
			mp[a[i]] = 1;
		}
		sum += a[i];
		num++;
		if(sum == 0) {
			ans[++j] = num;
			num = 0;
			mp.clear();
		}
	}
	
	if(sum != 0) return puts("-1"), 0;
	
	printf("%d\n", j);
	for(int i = 1;i <= j; i++) {
		printf("%d ", ans[i]);
	}
}