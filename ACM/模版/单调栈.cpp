#include <iostream>
#include <stack>
using namespace std;
struct node
{
	int num,pos;
}p;

int a[100],ans[100],i,n;

stack <node> q;

int main()
{
	cin >> n;
	for(i = 1;i <= n; i++) cin >> a[i];
	p.num = a[1],p.pos = 1;
	q.push(p);
	for(i = 2;i <= n ;i++)
	{
		while(!q.empty() && q.top().num < a[i])
		{
			ans[q.top().pos] = i;
			q.pop();
		}
		p.num = a[i],p.pos = i;
		q.push(p);
	}
	while(!q.empty())
	{
		ans[q.top().pos] = 0;
		q.pop();
	}
	for(i = 1;i <= n; i++)
		cout << ans[i] << " ";
}