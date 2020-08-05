#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[200005];
ll Max ,Max2;
ll sum = 0,sumf,ans;

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	scanf("%d", &n);
	
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sort(a+1, a+1+n);
	Max = a[n]; Max2 = a[n-1];
//	cout << "Max = " << Max << " Max2 = " << Max2 << endl;
	
	sumf = Max*n;
	ll sheng = sumf - sum;
	ll t = Max - a[1];
	for(int i = 2;i <= n-1; i++) {
		t = gcd(t, Max-a[i]);
	}
	
//	cout << "t = " << t << endl;
	
	printf("%lld %lld\n", sheng/t, t);
}