#include <bits/stdc++.h>
using namespace std;

int _, n, p, k;
long long x, y;
char s[100005];
bool vis[100005];
long long price[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &p, &k);
		for(int i = 1;i <= n; i++) vis[i] = 0;
		scanf("%s", (s+1));
		scanf("%lld %lld", &x, &y);
		
		for(int i = 1;i <= n; i++) {
			int pos = i;
			while(pos <= n) {
				if(vis[pos]) break;
				vis[pos] = 1;
				if(s[pos] == '0') {
					if(pos - k >= 1) price[pos] = price[pos-k] + x;
					else price[pos] = x;
				} 
				else {
					if(pos - k >= 1) price[pos] = price[pos-k];
					else price[pos] = 0;
				} 
				
				pos += k;
			}
		}
		
		long long ans = 1e18;
		long long xiao = 0;
		
		for(int i = p;i <= n; i++) {
			int pos = i;
			long long now = xiao;
			int cnt = (n-pos)/k;
			int pre = pos-k>=1?pos-k:0;
			now += price[pos+cnt*k]-price[pre];
			ans = min(ans, now);
			
			xiao += y;
		}
		
		printf("%lld\n", ans);
	}
}