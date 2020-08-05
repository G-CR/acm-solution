#include<iostream>
using namespace std;

int n, p, a, b, m, x, y, ans;
struct node
{
	int l, r, w, f;
}tree[400001];

void build(int k, int ll, int rr) //建树
{
	tree[k].l = ll, tree[k].r = rr;
	if(tree[k].l == tree[k].r)
	{
		scanf("%d", &tree[k].w);
		return;
	}
	
	int m = (ll + rr) / 2;
	build(2*k, ll, m);
	build(2*k+1, m+1, rr);
	
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void down(int k)
{
	tree[2*k].f += tree[k].f;
	tree[2*k+1].f += tree[k].f;
	tree[2*k].w += tree[k].f * (tree[2*k].r - tree[2*k].l + 1);
	tree[2*k+1].w += tree[k].f * (tree[2*k+1].r - tree[2*k+1].l + 1);
	tree[k].f = 0;
}

void ask_point(int k) // µ•µ„≤È—Ø (xŒ™–Ë“™≤È—ØµƒŒª÷√) 
{
	if(tree[k].l == tree[k].r)
	{
		ans = tree[k].w;
		return;
	}
	
	if(tree[k].f) down(k);
	
	int m = (tree[k].l + tree[k].r) / 2;
	if(x <= m) ask_point(2*k) ;
	else ask_point(2*k+1);
}

void change_point(int k) // µ•µ„–ﬁ∏ƒ (xŒ™–Ë“™–ﬁ∏ƒ ˝µƒŒª÷√ yŒ™–Ë“™‘ˆº”µƒ÷µ) 
{
	if(tree[k].l == tree[k].r)
	{
		tree[k].w += y;
		return;
	}
	
	if(tree[k].f) down(k);
	
	int m = (tree[k].l + tree[k].r) / 2;
	if(x <= m) change_point(2*k);
	else change_point(2*k+1);
	
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

void ask_interval(int k) // «¯º‰≤È—Ø (a,b∑÷±Œ™≤È—Ø◊Û”“±ﬂΩÁ) 
{
	if(a <= tree[k].l && tree[k].r <= b)
	{
		ans += tree[k].w;
		return;
	}
	
	if(tree[k].f) down(k);
	
	int m = (tree[k].l + tree[k].r) / 2;
	if(a <= m) ask_interval(2*k);
	if(b > m) ask_interval(2*k+1);
}

void change_interval(int k) // «¯º‰–ﬁ∏ƒ (a,b∑÷±Œ™≤È—Ø◊Û”“±ﬂΩÁ yŒ™–Ë“™‘ˆº”µƒ÷µ) 
{
	if(a <= tree[k].l && tree[k].r <= b)
	{
		tree[k].w += (tree[k].r - tree[k].l + 1) * y;
		tree[k].f += y;
		return;
	}
	
	if(tree[k].f) down(k);
	
	int m = (tree[k].l + tree[k].r) / 2;
	if(a <= m) change_interval(2*k);
	if(b > m) change_interval(2*k+1);
	
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}

int main()
{
	scanf("%d", &n); // n∏ˆΩ⁄µ„ 
	build(1, 1, n); // Ω® ˜
	scanf("%d", &m); // m÷÷≤Ÿ◊˜
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&p);
		ans = 0;
		if(p == 1) // µ•µ„≤È—Ø 
		{
			scanf("%d", &x);
			ask_point(1);
			printf("%d\n",ans); 
		}
		
		else if(p == 2) // µ•µ„–ﬁ∏ƒ 
		{
			scanf("%d %d", &x, &y); 
			change_point(1);
		}
		
		else if(p == 3) // «¯º‰≤È—Ø 
		{
			scanf("%d %d", &a, &b);
			ask_interval(1);
			printf("%d\n", ans);
		}
		
		else // «¯º‰–ﬁ∏ƒ 
		{
			scanf("%d %d %d", &a, &b, &y);
			change_interval(1);
		}
	}
}
