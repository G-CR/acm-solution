#include <bits/stdc++.h>
using namespace std;

int n;
long long x, y, a, b;
long long task[100005];
vector <long long> g[100005];
pair <long long, long long> pa[100005];

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

long long dfs(int pos) {
	long long sum = task[pos];
	for(int i = 0;i < g[pos].size(); i++) {
		long long to = g[pos][i];
		long long need = dfs(to);
		long long num = need/pa[to].second+(need%pa[to].second!=0);
		task[pos] += num*pa[to].first;
	}
	return task[pos];
}


int main() {
	scanf("%d", &n);
	for(int i = 1;i < n; i++) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		long long t = gcd(a, b);
		a /= t; b /= t;
		g[x].push_back(y);
		pa[y] = make_pair(a, b);
	}
	
	for(int i = 2;i <= n; i++) {
		scanf("%lld", &task[i]);
	}
	
	printf("%lld\n", dfs(1));
}