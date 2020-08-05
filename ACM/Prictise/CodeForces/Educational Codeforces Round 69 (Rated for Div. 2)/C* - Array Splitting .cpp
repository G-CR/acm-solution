#include <iostream>
#include <algorithm>
using namespace std;
int n,k,i,ans;

int main()
{
	cin >> n >> k;
	int a[n+1],b[n];
	cin >> a[1];
	for(i = 2;i <= n; i++)
	{
		cin >> a[i];
		b[i-1] = a[i] - a[i-1];
	}
	sort(b+1,b+n);
	ans = a[n] - a[1];
	for(i = 1;i < k; i++)
		ans -= b[n-i];
	cout << ans << endl;
}