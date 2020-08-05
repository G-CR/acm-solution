#include <iostream>
#include <stack>
using namespace std;
const int N = 5*1e5;
struct zjen
{
	int pos,num;
}a[N],b[N];

stack <zjen> p,q;
int n,i,ans1[N],ans2[N],ans;

int main()
{
	while(~scanf("%d",&n))
	{
		for(i = 1;i <= n; i++) {scanf("%d", &a[i].num); a[i].pos = i;}
		for(i = 1;i <= n; i++) {scanf("%d", &b[i].num); b[i].pos = i;}
		
		a[0].num = b[0].num = -1;
		a[0].pos = b[0].pos = 0;
		
		for(i = n;i >= 0; i--)
		{
			while(!p.empty() && p.top().num > a[i].num)
			{
				ans1[p.top().pos] = i;
				p.pop();
			}
			p.push(a[i]);
		}
		
		for(i = n;i >= 0; i--)
		{
			while(!q.empty() && q.top().num > b[i].num)
			{
				ans2[q.top().pos] = i;
				q.pop();
			}
			q.push(b[i]);
		}
		
		for(i = 1;i <= n; i++)
		{
			if(ans1[i] != ans2[i])
			{
				ans = i-1;
				break;
			}
		}
//		cout << "i = " << i << endl;
		if(i == n+1) ans = n;
		cout << ans << endl;
	}
}