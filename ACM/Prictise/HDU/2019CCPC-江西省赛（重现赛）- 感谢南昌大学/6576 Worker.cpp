#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long sum,i,j,m,n,a[1100],cur;
long long gcd(long long a,long long b)
{		
	while(a != b)
	{
		if(a>b) a = a - b;
		else b = b - a;
	}
	return a;
}

int main()
{
	while(~scanf("%lld %lld", &n, &m))
	{
		
		for(i = 1;i <= n; i++) scanf("%lld",&a[i]);
		long long t = a[1];
		
		for(i = 2;i <= n; i++)
		{
			t = (t*a[i])/gcd(t,a[i]);
		}
		
		sum = 0;
		for(i = 1;i <= n; i++)
		{
			a[i] = t/a[i];
			sum += a[i];
		}
		
		if(m % sum == 0) 
		{
			cur = m/sum;
			cout << "Yes" << endl;
			for(i = 1;i < n; i++)
				printf("%lld ", a[i]*cur);
			printf("%lld\n",a[n]*cur);
		}
		else cout << "No" << endl;
	}
	return 0;
}