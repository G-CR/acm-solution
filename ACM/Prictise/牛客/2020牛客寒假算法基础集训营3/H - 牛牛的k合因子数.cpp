#include <bits/stdc++.h>
using namespace std;

const int M = 100001;
bool isprime[M];
int n, m, k;
int ans[100005];

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
}

int main() {
	solve();
	scanf("%d %d", &n, &m);
	for(int i = 4;i <= n; i++) {
		if(isprime[i]) continue;
		int t = sqrt((double(i)));
		int num = isprime[i]?0:1;
		for(int j = 2;j <= t; j++) {
			if(i%j==0) {
				if(!isprime[j]) num++;
				if(!isprime[i/j] && j != i/j) num++;
			}
		}
		ans[num]++;
//		cout << "i: " << i << " num: " << num << endl;
	}
	
	while(m--) {
		scanf("%d", &k);
		printf("%d\n", ans[k]);
	}
}