#include <iostream>
#include <algorithm>
using namespace std;

int T,n,i;
int a[1000000];

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1;i <= n; i++) cin >> a[i];
		sort(a+1, a+1+n);
		int ans = min(a[n-1]-1,n-2);
		cout << ans << endl;
	}
}