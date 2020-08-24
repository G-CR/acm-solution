#include <bits/stdc++.h>
using namespace std;

int _, n;
const int M = 200005;
vector <int> g[M];
vector <pair<int, int> > ans;
bool isprime[M], vis[M];
void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 0;
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		ans.clear();
		for(int i = 1;i <= n; i++) g[i].clear(), vis[i] = 0;
		int num = 0;
		for(int i = 2;i <= n/2; i++) {
			if(isprime[i]) {
				for(int j = i;j <= n; j+=i) {
					g[num].push_back(j);
				}
				num++;
			}
		}
		
		vector <int> t, nic;
		for(int i = num-1;i >= 0; i--) {
			t.clear(); nic.clear();
			for(auto j: g[i]) {
				if(vis[j]) continue;
				vis[j] = 1;
				t.push_back(j);
			}
			
			if(t.size()%2==0) nic = t;
			else {
				bool ok = 0;
				for(auto j: t) {
					if(!ok && j%2==0) ok = 1, vis[j] = 0;
					else nic.push_back(j);
				}
			}
			for(int j = 1;j < nic.size(); j += 2) {
				ans.push_back(make_pair(nic[j-1], nic[j]));
			}
		}
		
		printf("%d\n", (int)ans.size());
		for(auto i: ans) {
			printf("%d %d\n", i.first, i.second);
		}
	}
}