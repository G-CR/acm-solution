#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2*1e6+5;

struct node
{
	int like,pos; // like为喜爱程度的前缀和
}fruit[N];

bool cmp(node a,node b)
{
	if(a.like == b.like)
		return a.pos > b.pos;
	return a.like < b.like;
}

int n,i,x,minx,ans;

int main()
{
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &x);
		fruit[i].like = fruit[i-1].like+x;
		fruit[i].pos = i;
	}
	
	n++; // 把喜爱度为零的点也要包括
	minx = n;
	sort(fruit+1,fruit+1+n,cmp);
	
	for(i = 1;i <= n; i++)
	{
		if(minx > fruit[i].pos) minx = fruit[i].pos;
		if(minx < fruit[i].pos) 
			ans = max(ans,fruit[i].pos - minx);
	}
	cout << ans << endl;
}