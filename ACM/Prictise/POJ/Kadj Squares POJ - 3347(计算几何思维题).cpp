#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, h[55], l[55], r[55];
vector <int> ans;

int main() {
	while(~scanf("%d", &n) && n) {
		ans.clear();
		for(int i = 0;i <= n; i++) {
			h[i] = l[i] = r[i] = 0;
		}
		for(int i = 1;i <= n; i++) {
			scanf("%d", &h[i]);
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= i-1; j++) {
				l[i] = max(l[i], r[j]-abs(h[i]-h[j]));
			}
			r[i] = l[i]+2*h[i];
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= i-1; j++) {
				if(h[i] < h[j] && l[i] < r[j]) {
					l[i] = r[j];
				}
				else if(h[i] > h[j] && l[i] < r[j]) {
					r[j] = l[i];
				}
			}
		}
		
		for(int i = 1;i <= n; i++) if(l[i] < r[i]) ans.push_back(i);
		for(int i = 0;i < ans.size(); i++) {
			printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
		}
	}
}