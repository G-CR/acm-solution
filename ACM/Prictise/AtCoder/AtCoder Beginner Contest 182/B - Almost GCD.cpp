#include <bits/stdc++.h>
using namespace std;

int n, a[103];
map <int, int> num;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int t = a[i];
		for(int j = 2; j <= t; j++) {
			if(t % j == 0) num[j]++;
		}
	}
	
	int ans = 0, res;
	for(auto i: num) {
		if(ans <= i.second) {
			ans = i.second;
			res = i.first;
		}
	}
	
	printf("%d\n", res);
}