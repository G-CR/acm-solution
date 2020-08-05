//http://codevs.cn/problem/1080/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l, r, w, f;
}tree[400005];

int n,m,a,b,x,y,ans,t1,t2,t3;

void build(int k,int ll, int rr)
{
	tree[k].l = ll, tree[k].r = rr;
	if(tree[k].l == tree[k].r)
	{
		scanf("%d",&tree[k].w);
		return;
	}
	
	int m = (ll + rr) / 2;
	build(2*k, ll, m);
	build(2*k+1, m+1, rr);
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void down(int k)
{
	tree[2*k].f = tree[k].f;
	tree[2*k+1].f = tree[k].f;
	tree[2*k].w = tree[k].f * (tree[2*k].r - tree[2*k].l + 1);
	tree[2*k+1].w = tree[k].f * (tree[2*k+1].r - tree[2*k+1].l + 1);
	tree[k].w = tree[2*k].w	+ tree[2*k+1].w;
}

void change_point(int k)
{
	if(tree[k].l == tree[k].r)
	{
		tree[k].w += t3;
		return;
	}
	
	int m = (tree[k].l + tree[k].r) / 2;
	if(m >= t2) change_point(2*k);
	else change_point(2*k+1);
	
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void ask_interval(int k)
{
	if(t2 <= tree[k].l && t3 >= tree[k].r)
	{
		ans += tree[k].w;
		return;
	}
	
	if(tree[k].f) down(k);
	int m = (tree[k].l + tree[k].r) / 2;
	if(t2 <= m) ask_interval(2*k);
	if(t3 > m) ask_interval(2*k+1);
}


int main()
{
	scanf("%d",&n);
	
	build(1, 1, n);

	scanf("%d",&m);
	while(m--)
	{
		ans = 0;
		scanf("%d %d %d", &t1, &t2, &t3);
		if(t1 == 1)
			change_point(1);
		
		
		else if(t1 == 2)
		{
			ask_interval(1);
			printf("%d\n",ans);
		}
	}
}
