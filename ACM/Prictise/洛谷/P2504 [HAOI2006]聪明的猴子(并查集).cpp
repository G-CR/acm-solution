//https://www.luogu.org/problemnew/show/P2504
#include<bits/stdc++.h>
using namespace std;
const int n = 10000005;

struct node
{
	int a,b;
	double s;
}tree[n];

int x[n],y[n],father[n],Rank[n],N,M,i,j;
int monkey[510];

int find(int x)
{
	if(x == father[x]) return x;
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

bool cmp(node a,node b)
{
	return a.s < b.s;
}

int main()
{
	cin >> M;
	for(i = 1;i <= M; i++) cin >> monkey[i];
	sort(monkey+1,monkey+1+M);
	
	cin >> N;
	for(i = 1;i <= N; i++) cin >> x[i] >> y[i],father[i] = i;
	
	int cnt = 0;
	for(i = 1;i <= N; i++)
		for(j = 1;j <= N; j++)
		{
			tree[++cnt].a = i;
			tree[cnt].b = j;
			tree[cnt].s = (double)sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
		}
	
	sort(tree+1,tree+1+cnt,cmp);
	
	int top = 0,dead = 0;
	for(i = 1;i <= cnt; i++)
	{
		if(find(tree[++top].a) != find(tree[top].b))
		{
			unionSet(tree[top].a,tree[top].b);
			while(monkey[dead] < tree[top].s)
			{	
				if(dead > M)
				{
					cout << "0" << endl;
					return 0;
				}
				dead++;
				
			}
		}
	}
	cout << M - dead + 1 << endl;
}