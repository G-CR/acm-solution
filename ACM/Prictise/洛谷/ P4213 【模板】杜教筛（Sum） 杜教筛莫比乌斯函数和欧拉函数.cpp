#include<bits/stdc++.h>
#define N 6000010
using namespace std;
bool vis[N];
int mu[N],sum1[N],phi[N];
long long sum2[N];
int cnt, prim[N];
unordered_map<long long,long long> w1;
unordered_map<int,int> w;

void get(int maxn) {
    phi[1]=mu[1]=1;
    for(int i=2;i<=maxn;i++) {
        if(!vis[i]) {
            prim[++cnt]=i;
            mu[i]=-1;phi[i]=i-1;
        }
        for(int j=1;j<=cnt&&prim[j]*i<=maxn;j++) {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) {
                phi[i*prim[j]]=phi[i]*prim[j];
                break;
            }
            else mu[i*prim[j]]=-mu[i],phi[i*prim[j]]=phi[i]*(prim[j]-1);
        }
    }
    for(int i=1;i<=maxn;i++)
        sum1[i]=sum1[i-1]+mu[i],sum2[i]=sum2[i-1]+phi[i];
}

int djsmu(long long x) {
    if(x<=N) return sum1[x];
    if(w[x]) return w[x];
    int ans=1;
    for(int l=2,r;l>=0&&l<=x;l=r+1) {
        r=x/(x/l);
        ans-=(r-l+1)*djsmu(x/l);
    }
    return w[x]=ans;
}

long long djsphi(long long x) {
    if(x<=N)return sum2[x];
    if(w1[x])return w1[x];
    long long ans=x*(x+1)/2;
    for(long long l=2,r;l<=x;l=r+1) {
        r=x/(x/l);
        ans-=(r-l+1)*djsphi(x/l);
    }
    return w1[x]=ans;
}

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    get(N);
    while(t--) {
        scanf("%lld", &n);
        printf("%lld %d\n", djsphi(n), djsmu(n));
    }
    return 0;
}