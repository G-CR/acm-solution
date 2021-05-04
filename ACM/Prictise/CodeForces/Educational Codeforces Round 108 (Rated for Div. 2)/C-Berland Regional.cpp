#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int _, n;
int u[N];
long long s[N];

vector <long long> g[N];
vector <long long> pre[N];
long long p[N];
set <int> st;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	scanf("%d", &_); while(_--) {
		scanf("%d", &n); st.clear();
		for(int i = 1; i <= n; i++) {
			g[i].clear(); pre[i].clear();
			scanf("%d", &u[i]);
			st.insert(u[i]);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &s[i]);
		}
		for(int i = 1; i <= n; i++) {
			if(g[u[i]].empty()) g[u[i]].push_back(1e18);
			g[u[i]].push_back(s[i]);
		}
		for(int i : st) {
			sort(g[i].begin(), g[i].end(), cmp);
			p[0] = 0;
			for(int j = 1; j < g[i].size(); j++) {
				p[j] = p[j-1] + g[i][j];
			}
			for(int j = 0; j < g[i].size(); j++) {
				pre[i].push_back(p[j]);
			}
		}
		
		bool ok = 1;
		for(int k = 1; k <= n; k++) {
			if(!ok) {printf("0 "); continue;}
			long long ans = 0;
			for(int i : st) {
				int sz = pre[i].size()-1;
				int pos = sz / k * k;
				ans += pre[i][pos];
			}
			if(ans == 0) ok = 0;
			printf("%lld ", ans);
		}
		puts("");
	}
}