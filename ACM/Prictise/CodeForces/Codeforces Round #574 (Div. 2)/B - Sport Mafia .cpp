#include <iostream>
#include <algorithm>
using namespace std;

long long n,k,i,sum;

int main()
{
	scanf("%lld %lld",&n, &k);
	for(i = 1;i <= n; i++)
	{
		sum = (1+i)*i/2;
		if(sum-k == n-i) break;
	}
	cout << sum - k;
}