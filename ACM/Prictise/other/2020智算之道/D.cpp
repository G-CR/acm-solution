#include <bits/stdc++.h>
using namespace std;
#define PII pair <ll,ll>
#define fr first
#define sc second
#define mp make_pair
#define ll long long
#define ut unsigned int

ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=8e7+5;

bool mark[N];
vector<ll> p;
vector<PII> ok;
int cnt;

void initial(){
	p.push_back(0);
	cnt=0;
	for (int i=2 ; i<N ; ++i){
		if (!mark[i]) p.push_back(i),cnt++;
		for (int j=1 ; j<=cnt && i*p[j] < N ; ++j){
			mark[i*p[j]]=1;
			if (!(i%p[j])) break;
		}
	}
}


int main(){
	initial();

	ll n=input();
	ut a,b;
	scanf("%u %u", &a, &b);

	for(int i=1;i<=cnt;i++){
		if(p[i]>n) break;
		if(p[i]*p[i]>n){
			break;
		}else{
			for(ll j=p[i];j<=n;j=j*p[i]){
				if(j>n) break;
				ok.push_back(mp(j,p[i]));
			}
		}
	}

	sort(ok.begin(),ok.end());

	int now=0;
	for(int i=1;i<=cnt;i++){
		if(p[i]>n) break;
		while(now<ok.size()&&ok[now].fr<p[i]){
			a=a*ok[now].sc+b;
			now++;
		}
		if(p[i]*p[i]>n){
			a=a*p[i]+b;
		}
	}

	while(now<ok.size()) a=a*ok[now].sc+b,now++;

	printf("%u\n", a);
}