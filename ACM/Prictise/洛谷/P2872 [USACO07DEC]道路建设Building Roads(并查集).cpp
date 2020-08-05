//https://www.luogu.org/problemnew/show/P2872
#include<bits/stdc++.h>
using namespace std;
const int N = 1000001;
struct node
{
	int a,b;
	double s;
}place[N];

int i,j,n,m,cnt,p,q;
int x[N],y[N],father[N],Rank[N];
double ans = 0.0;

bool cmp(node x,node y)
{
	if(x.s == y.s)
		return x.a < y.a;
	return x.s < y.s;
}

int find(int x)
{
	if(father[x] == x) return x;
	return father[x] = find(father[x]);
}

void unionSet(int x,int y)
{
	if((x = find(x)) == (y = find(y))) return;
	if(Rank[x] > Rank[y]) father[y] = x;
	else
	{
		father[x] = y;
		if(Rank[x] == Rank[y]) Rank[y]++;
	}
}

int main()
{
	cin >> n >> m;
	for(i = 1;i <= n; ++i) cin >> x[i] >> y[i],father[i] = i;
	
	for(i = 1;i <= n; i++)
		for(j = i+1;j <= n; j++)
		{
			place[++cnt].a = i;
			place[cnt].b = j;
			place[cnt].s = (double)sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
		}
		
	for(i = 1;i <= m; ++i)
	{
		cin >> p >> q;
		place[++cnt].a = p;
		place[cnt].b = q;
		place[cnt].s = 0.0;
	}
	
	sort(place+1,place+1+cnt,cmp);
	
	int top = 0;
	for(i = 1;i <= cnt; i++)
	{
		if(find(place[++top].a) != find(place[top].b))
		{
			ans += place[top].s;
			unionSet(place[top].a,place[top].b);
		}
	}
	
	printf("%.2lf\n", ans);
	return 0;
}