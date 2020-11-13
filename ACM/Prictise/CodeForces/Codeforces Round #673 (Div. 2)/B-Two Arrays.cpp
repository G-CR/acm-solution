#include <bits/stdc++.h>
using namespace std;
 
int _, n, T;
int a[100005];
map <int, int> mp;
bool vis[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		mp.clear();
		scanf("%d %d", &n, &T);
		for(int i = 1;i <= n; i++) {
			vis[i] = 0;
			scanf("%d", &a[i]);
		}
		
		for(int i = 1;i <= n; i++) {
			if(!mp[T-a[i]]) {
				mp[a[i]] = 1;
			}
		}
		
		if(T%2 == 0) {
			int num = 0, t = T/2;
			for(int i = 1;i <= n; i++) {
				if(t == a[i]) num++;
			}
			++num /= 2;
			for(int i = 1; num; i++) {
				if(a[i] == T/2) {
					vis[i] = 1;
					num--;
				} 
			}
			mp[T/2] = 0;
		}
		
		for(int i = 1;i <= n; i++) {
			if(mp[a[i]]) {
				vis[i] = 1;
			}
		}
		
		
		
		for(int i = 1;i <= n; i++) {
			printf("%d ", vis[i]);
		}
		puts("");
	}
}