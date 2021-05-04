#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[55][55];
multiset <int> st;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector <int> ans;
	for(int i = 1; i+k-1 <= n; i++) {
		for(int j = 1; j+k-1 <= m; j++) {
			int ma = -1;
			for(int p = i; p <= i+k-1; p++) {
				for(int q = j; q <= j+k-1; q++) {
					ma = max(ma, a[p][q]);
				}
			}
			
			ans.push_back(ma);
		}
	}
	
	int fn = n - k + 1, fm = m - k + 1;
	int p = 0;
	printf("%d %d\n", fn, fm);
	for(int i = 1; i <= fn; i++) {
		for(int j = 1; j <= fm; j++) {
			printf("%d ", ans[p++]);
		}
		puts("");
	}
}