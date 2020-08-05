#include <bits/stdc++.h>
using namespace std;
int ok[101][101], num[10005], n, m, k, t;
char a[100005], b[100005];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&m,&k);
		scanf("%s %s", a+1, b+1);
		long long ans=0;
		memset(ok,0,sizeof(ok));
		memset(num,0,sizeof(num));
		for(int i = 1;i+k-1 <= n; i++) ok[a[i]-'a'+1][a[i+k-1]-'a'+1] = 1;
		for(int i=1;i <= m; i++) {
			num[b[i]-'a'+1]++;
			for(int j = 1; j <= 26; j++) {
				if(ok[j][b[i]-'a'+1] == 0) continue;
				ans += num[j];
			}
		}
		printf("%lld\n",ans);
	}
}