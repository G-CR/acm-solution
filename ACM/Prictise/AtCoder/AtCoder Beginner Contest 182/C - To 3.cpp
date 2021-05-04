#include <bits/stdc++.h>
using namespace std;

long long n;
vector <int> a;

int dfs(int pos, int num, int tot) {
	if(pos == a.size()) {
		if(num && tot % 3 == 0) return num;
		return -1;
	}
	int res = -1;
	res = max(res, dfs(pos+1, num+1, tot+a[pos]));
	res = max(res, dfs(pos+1, num, tot));
	return res;
}

int main() {
	scanf("%lld", &n);
	bool ok = 0;
	while(n) {
		int t = n % 10;
		n /= 10;
		if(t % 3) {
			a.push_back(t);
		}
		else ok = 1;
	}
	
	int sum = 0;
	for(int i : a) sum += i;
	if(sum % 3 == 0) puts("0");
	else {
		int mod = sum % 3;
		int ans = dfs(0, 0, 0);
		if(ans == -1) {
			if(ok) printf("%lu\n", a.size());
			else puts("-1");
		}
		else printf("%d\n", (int)a.size()-ans);
	}
}