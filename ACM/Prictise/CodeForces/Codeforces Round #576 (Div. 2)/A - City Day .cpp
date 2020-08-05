#include <bits/stdc++.h>
using namespace std;

int n,x,y,ans;
int a[100005];

bool pre(int p)
{
	for(int i = p;i >= p-x; i--)
	{
		if(i <= 0) return true;
		if(a[p] > a[i]) return false;
	}
	return true;
}

bool beh(int p)
{
	for(int i = p; i <= p+y; i++)
	{
		if(i > n) return true;
		if(a[p] > a[i]) return false;
	}
	return true;
}

int main()
{
	cin >> n >> x >> y;
	for(int i = 1;i <= n ;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n ; i++)
	{
		//cout << "pre = " << pre(i) << " beh = " << beh(i) << endl;
		if(pre(i) && beh(i))
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}