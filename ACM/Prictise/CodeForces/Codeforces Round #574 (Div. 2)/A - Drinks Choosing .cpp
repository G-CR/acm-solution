#include <iostream>
#include <algorithm>
using namespace std;

int n,k,i,t,ans,sum,x,count_[1005];

int main()
{
	scanf("%d %d",&n, &k);
	
	if(n%2) t = (n+1)/2;
	else t = n/2;
	
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &x);
		count_[x]++;
	}
	
	for(i = 1;i <= k; i++)
	{
		ans += count_[i]/2;
		sum += count_[i]%2;
	}
	cout << ans*2+(t-ans) << endl;
}