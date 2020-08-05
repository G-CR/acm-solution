#include <bits/stdc++.h>
using namespace std;

int k, n, t, a, b;
vector <int> all, alice, bob;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &t, &a, &b);
		if(a&b) all.push_back(t);
		else if(a) alice.push_back(t);
		else if(b) bob.push_back(t);
	}
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	
	int nk = all.size(), na = alice.size(), nb = bob.size();
	if(nk+min(na, nb) < k) puts("-1");
	else {
		for(int i = 0;i < min(na, nb); i++) {
			all.push_back(alice[i]+bob[i]);
		}
		sort(all.begin(), all.end());
		
		int ans = 0;
		for(int i = 0;i < k; i++) ans += all[i];
		printf("%d\n", ans);
	}
}