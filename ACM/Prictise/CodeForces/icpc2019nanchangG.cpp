#include<bits/stdc++.h>using namespace std;const long long mod = 998857459;long long fac[100007];int n,m;long long a[100005],b[3000],sum[3000],fin[100005];
int mp[100005];
int gao(long long x) {
	int ans=-1,l=1,r=n,mid;
	while(l<=r){
		int mid=(l+r)/2;
		if(fin[mid]>=x){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){	long long now = 1;	for(long long i = 1;i <= 2802; i++) {		now = (now * i) % mod;		fac[i] = now;	}	scanf("%d %d", &n, &m);	for(int i = 1;i <= n; i++) {		scanf("%lld", &a[i]);		a[i] = fac[a[i]];	}
	int cnt = 0; mp[0] = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i]) {
			b[++cnt] = a[i];
			mp[cnt] = i;
		}
	}
	for(int i = 1;i <= cnt; i++) {
		sum[i] = (sum[i-1] + b[i]) % mod;
	}
//	for(int i = 1;i <= cnt; i++) {
//		printf("%lld ", sum[i]);
//	} puts("");
	for(int len = 1;len <= cnt; len++) {		int pos = len;
		for(int i = pos;i <= cnt; i++) {
			long long t = (sum[i] - sum[i-len] + mod) % mod;
			fin[mp[i]-mp[i-len+1]+1] = max(t, fin[mp[i]-mp[i-len+1]+1]);
		}	}
	for(int i=2;i<=n;i++){
		fin[i]=max(fin[i],fin[i-1]);
	}	long long x;	while(m--) {		scanf("%lld", &x);		int ans = gao(x);		printf("%d\n", ans);	}	}