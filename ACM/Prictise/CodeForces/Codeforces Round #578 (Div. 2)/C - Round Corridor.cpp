#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,q,t;
ll sx,sy,ex,ey;

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	else return gcd(b, a%b);
}

ll sst(ll num,ll key)
{
	if(num == 1) return key/(n/t);
	else return key/(m/t);
}

int main() 
{
	cin >> n >> m >> q;
	t = gcd(max(n,m),min(n,m));
	while(q--)
	{
		cin >> sx >> sy >> ex >> ey;
		if(sst(sx,sy-1) == sst(ex,ey-1)) puts("YES");
		else puts("NO");
	}
}