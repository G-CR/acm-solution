#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[5005][5005], maxn[5005][5005];
int gcd(int a, int b) {return b==0?a:gcd(b,a%b);}
int lcm(int a, int b) {return a*b/gcd(a,b);}

deque <int> q;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			a[i][j] = lcm(i, j);
		}
	}
	
	for(int i = 1;i <= n; i++) {
		q.clear();
		for(int j = 1;j <= m; j++) {
			while(!q.empty() && a[i][q.front()] < a[i][j]) q.pop_back();
			q.push_back(j);
			while(q.front() <= j-k) q.pop_front();
			maxn[i][j] = a[i][q.front()];
		}
	}
	
	for(int j = 1;j <= m; j++) {
		q.clear();
		for(int i = 1;i <= n; i++) {
			while(!q.empty() && maxn[q.front()][j] < maxn[i][j]) q.pop_back();
			q.push_back(i);
			while(q.front() <= i-k) q.pop_front();
			a[i][j] = maxn[q.front()][j];
		}
	}
	
	long long ans = 0;
	for(int i = k;i <= n; i++) {
		for(int j = k;j <= m; j++) {
			ans += a[i][j];
		}
	}
	printf("%lld\n", ans);
}