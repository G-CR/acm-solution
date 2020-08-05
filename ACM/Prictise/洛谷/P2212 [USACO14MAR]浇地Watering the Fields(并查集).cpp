//https://www.luogu.org/problemnew/show/P2212
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int n = 1e7+10;

struct node
{
	ll a,b,c;
} place[n];

ll x[n],y[n],Rank[n],father[n];
ll i,j,N,C;

ll find(ll x)
{
	if(x == father[x]) return x;
	return father[x] = find(father[x]);
}

void unionSet(ll x, ll y)
{
	if(Rank[x] > Rank[y]) father[y] = x;
	else
	{
		father[x] = y;
		if(Rank[x] == Rank[y]) Rank[y]++;
	}
}

bool cmp(node a,node b)
{
	if(a.c == b.c) return a.a < b.a;
	return a.c < b.c;
}

int main()
{
	cin >> N >> C;
	for(i = 1;i <= N; i++) cin >> x[i] >> y[i],father[i] = i;
	
	ll cnt = 0;
	for(i = 1;i <= N; i++)
		for(j = i+1;j <= N; j++)
		{
			place[++cnt].a = i;
			place[cnt].b = j;
			place[cnt].c = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}

	sort(place+1,place+1+cnt,cmp);
	
	ll top = 0,sum = N-1;
    ll cost = 0;
	for(i = 1;i <= cnt; i++)
	{
		if(find(place[i].a) != find(place[i].b))
		{
			if(place[i].c >= C)
			{
				sum--;
				cost += place[i].c;
				unionSet(find(place[i].a), find(place[i].b));
			}
		}
	}
	
//	cout << "sum = " <<sum << endl;
	
	if(sum > 0) cout << "-1" << endl;
	else cout << cost << endl;
}