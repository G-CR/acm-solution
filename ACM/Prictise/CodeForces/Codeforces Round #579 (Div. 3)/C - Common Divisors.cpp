#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[400005];

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main() 
{
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
	ll t = a[1];
	for(int i = 2;i <= n; i++)
		t = gcd(max(t,a[i]), min(t,a[i]));
		
//	cout << "t = " << t << endl;
	
	int ans = 0;
	for(int i = 1;i <= sqrt(t); i++)
	{
		if(!(t%i))
		{
//			cout << i << " ";
			if(t/i == i) ans++;
			else ans += 2;
		}
	}
//	cout << endl;
	printf("%d\n", ans);
}