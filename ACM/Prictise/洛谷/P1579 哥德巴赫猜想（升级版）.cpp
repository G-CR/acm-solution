#include <bits/stdc++.h>
using namespace std;

const int m = 20000;
bool a[m];
vector <int> vc;
int num;

void solve() {
	for(int i = 1;i <= m; i++) a[i] = 1;
	for(int i = 3;i <= m; i++) if(!(i%2)) a[i] = 0;
	for(int i = 2;i <= m; i++) {
		if(a[i]) {
			for(int j = i*2; j<= m; j += i)
				a[j] = 0;
		}
	}
	
//	for(int i = 2;i <= m; i++)
//		if(a[i]) cout << i << " ";
}

int main() {
	solve();
	for(int i = 2;i <= m; i++) {
		if(a[i]) vc.push_back(i);
	}
	scanf("%d", &num);
	
	bool ok = 0;
	int n = vc.size();
	for(int i = 0;i < n; i++) {
		for(int j = 0;j < n; j++) {
			int k = num-vc[i]-vc[j];
			if(k < 0) continue;
			if(a[k]) {
				ok = 1;
				printf("%d %d %d", vc[i], vc[j], k);
				break;
			}
		}
		if(ok) break;
	}
}