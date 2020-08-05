#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int t,n;
long long a[N],i;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i < n; ++i)
			scanf("%d", &a[i]);
			
		sort(a, a+n);

		long long boss = 1ll*a[0]*a[n-1];
//		cout << "boss = " << boss << endl;
		 
		int k = 1;
		for(i = 0;i < n; ++i) 
			if(boss % a[i]) 
				k = 0;
//		cout << "k = " << k << endl;
		
		int ans = 0;
		for(i = 2;i*i <= boss; ++i)
		{
			if(boss % i) continue;
			ans++;
			if(boss / i != i)
				ans++;
		}
//		cout << "r = " << r << endl;
		
		k&=(ans==n);
		cout << (k?boss:-1) << endl;
	}
}
