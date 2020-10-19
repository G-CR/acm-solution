#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[105], l[105], sum[105];
deque <int> q;
vector <int> v;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		v.clear();
		while(!q.empty()) q.pop_back();
		
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 1;i <= n; i++) {
			scanf("%d", &l[i]);
		}
		for(int i = 1;i <= n; i++) {
			if(!l[i]) v.push_back(a[i]);
		}
		sort(v.begin(), v.end(), cmp);
		
		for(int i: v) q.push_back(i);
		
		for(int i = 1;i <= n; i++) {
			if(!l[i]) {
				a[i] = q.front();
				q.pop_front();
			} 
		}
		
		for(int i = 1;i <= n; i++) {
			sum[i] = sum[i-1] + a[i];
		}
		
		for(int i = 1;i <= n; i++) printf("%d ", a[i]);
//		for(int i = 1;i <= n; i++) printf("%d ", sum[i]);
		puts("");
	}
}