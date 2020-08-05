#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int m = 100000;
bool a[N];
vector <int> vc;
queue<int> q;

void solve() {
	for(int i = 1;i <= m; i++) a[i] = 1;
	for(int i = 3;i <= m; i++) if(!(i%2)) a[i] = 0;
	for(int i = 2;i <= m; i++) {
		if(a[i]) {
			for(int j = i*2; j<= m; j += i)
				a[j] = 0;
		}
	}
}

int n;

int main() {
	solve();
	for(int i = 2;i <= 1000; i++) {
		if(a[i]) vc.push_back(i);
	}
	scanf("%d", &n);
	q.push(n);
	
	int num = 0;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		if(a[t]) continue;
		for(int i = 0;i < vc.size(); i++) {
			if(t % vc[i] == 0) {
				q.push(vc[i]);
				q.push(t/vc[i]);
				num++;
				break;
			}
		}
	}
	if(num%2) puts("Johnson");
	else puts("Nancy");
}