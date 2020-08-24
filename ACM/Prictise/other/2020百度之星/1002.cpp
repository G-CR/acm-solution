#include<bits/stdc++.h>
#define ll long long
#define N 1000007
using namespace std;
char s[N],t[N];
int ans,sum[N],cnt[N],gcr[N];
int n;
int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		scanf("%d",&n);
		scanf("%s%s",s+1,t+1);
		s[n+1]=t[n+1]='0';
		sum[n+1]=sum[n+2]=0;
		for (int i=n; i>=1; i--) {
			if (s[i]!=t[i]) sum[i]=1;
			else sum[i]=0;
			sum[i]=sum[i+1]+sum[i];
		}
		cnt[0]=0;
		gcr[0]=0;
		for (int i=1; i<=n; i++) {
			if (t[i]=='1') cnt[i]=1;
			else cnt[i]=0;

			cnt[i]=cnt[i-1]+cnt[i];

			if (s[i]=='0') gcr[i]=1;
			else gcr[i]=0;

			gcr[i]=gcr[i]+gcr[i-1];
		}
		ans=sum[1];
		for (int i=1; i<=n+1; i++) {
			int tmp=gcr[i-1]+cnt[i-1];
			if (s[i]=='0') tmp++;
			else tmp+=2;

			if (t[i]=='0') tmp++;
			tmp+=sum[i+1];

			ans=min(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}