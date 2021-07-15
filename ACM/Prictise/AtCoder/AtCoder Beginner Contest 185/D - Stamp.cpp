#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
vector <int> v;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}
	if(!m) return puts("1"), 0;
	if(m == n) return puts("0"), 0;
	
	sort(a+1, a+1+m);
	int len = 2e9;
	for(int i = 2; i <= m; i++) {
		if(a[i] - a[i-1] == 1) continue;
		len = min(len, a[i]-a[i-1]-1);
		v.push_back(a[i]-a[i-1]-1);
	}
	if(a[1] != 1) {
		len = min(len, a[1]-1);
		v.push_back(a[1]-1);
	} 
	if(a[m] != n) {
		len = min(len, n-a[m]);
		v.push_back(n-a[m]);
	}
	
	long long ans = 0;
	for(int i = 0; i < v.size(); i++) {
		long long res = v[i] / len;
		long long mod = v[i] % len;
		ans += mod?res+1:res;
	}
	
	printf("%lld\n", ans);
}