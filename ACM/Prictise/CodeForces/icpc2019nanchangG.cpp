#include<bits/stdc++.h>
int mp[100005];

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
	for(int len = 1;len <= cnt; len++) {
		for(int i = pos;i <= cnt; i++) {
			long long t = (sum[i] - sum[i-len] + mod) % mod;
			fin[mp[i]-mp[i-len+1]+1] = max(t, fin[mp[i]-mp[i-len+1]+1]);
		}
	for(int i=2;i<=n;i++){
		fin[i]=max(fin[i],fin[i-1]);
	}