//https://vjudge.net/contest/300042#problem/A
#include<iostream>
#define lll long long
using namespace std;

lll a,b,y,N,M,ans;
char t;

struct node
{
	lll l, r, w, f;
	node(){
		this->f=0;
	}
}tree[400005];

void build(lll k, lll ll,lll rr)
{
	tree[k].l = ll, tree[k].r = rr;
	if(tree[k].l == tree[k].r)
	{
		scanf("%lld",&tree[k].w);
		return;
	}
	
	lll m = (ll + rr) / 2;
	build(2*k, ll, m);
	build(2*k+1, m+1, rr);
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void down(lll k)
{
	tree[2*k].f += tree[k].f;
	tree[2*k+1].f += tree[k].f;
	tree[2*k].w += tree[k].f * (tree[2*k].r - tree[2*k].l + 1);
	tree[2*k+1].w += tree[k].f * (tree[2*k+1].r - tree[2*k+1].l + 1);
	tree[k].f = 0;
}

void change_interval(lll k)
{
	if(tree[k].l >= a && tree[k].r <= b)
	{
		tree[k].w += (tree[k].r - tree[k].l + 1) * y;
		tree[k].f += y;
		return;
	}
	if(tree[k].f) down(k);
	lll m = (tree[k].l + tree[k].r) / 2;
	if(m>=a) change_interval(2*k);
	if(m<b)change_interval(2*k+1);
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void ask_interval(lll k)
{
	if(tree[k].l >= a && tree[k].r <= b)
	{
		ans += tree[k].w;
		return;	
	}
	
	if(tree[k].f) down(k);
	
	lll m = (tree[k].l + tree[k].r) / 2;
	if(a <= m) ask_interval(2*k);
	if(b > m) ask_interval(2*k+1);
	
}


int main()
{
	scanf("%lld %lld", &N, &M);
	build(1, 1, N);
	while(M--)
	{
//		cout << "hello\n";
		ans = 0;
		a = 0;b = 0;y = 0;
//		scanf("%c",&t);
		cin >> t;
		if(t == 'Q')
		{
			scanf("%lld %lld",&a, &b);
			ask_interval(1);
			printf("%lld\n",ans);
		}
		else if(t == 'C')
		{
			scanf("%lld %lld %lld", &a, &b ,&y);
			change_interval(1);
		}
	}
}
