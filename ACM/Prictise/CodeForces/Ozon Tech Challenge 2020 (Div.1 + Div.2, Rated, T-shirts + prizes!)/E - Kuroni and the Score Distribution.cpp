#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[5005];
vector<int> ans;

int main() {
	num[1] = 0; num[2] = 0; num[3] = 1;
	for(int i = 4;i <= 5000; i++) {
		num[i] = num[i-1] + (i-1)/2;
	}
	scanf("%d %d", &n, &m);
	if(num[n] < m) return puts("-1"), 0;
	
	int p = 0;
	
	if(m)
	for(int i = 1;; i++) {
		if(ans.size() == n) break;
		ans.push_back(i);
		if(num[i+1] > m) {
			p = m-num[i];
			ans.push_back((i+1)-1+(i+1)-2*p);
			break;
		}
	}
	
	int si = ans.size();
	int t = si?ans[si-1]:1;
	while(ans.size() < n) {
		t += 5050;
		ans.push_back(t);
	}
	
	for(int i = 0;i < n; i++) printf("%d ", ans[i]);
	puts("");
}