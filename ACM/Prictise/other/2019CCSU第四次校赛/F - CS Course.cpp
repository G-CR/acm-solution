#include<iostream>
#define ll long long
using namespace std;
const ll N = 1e5+5;

int a[N];
int zSum_and[N], zSum_or[N], zSum_xor[N];
int fSum_and[N], fSum_or[N], fSum_xor[N];
int n, p, pi;

int main()
{
	while(~scanf("%d %d",&n, &p))
	{
		scanf("%d", &a[1]);
		
		zSum_and[1] = zSum_or[1] = zSum_xor[1] = a[1];
		for(int i = 2;i <= n; ++i)
		{
			scanf("%d",&a[i]);
			
			zSum_and[i] = zSum_and[i-1] & a[i];
			zSum_or[i] = zSum_or[i-1] | a[i];
			zSum_xor[i] = zSum_xor[i-1] ^ a[i];
		}
	
		fSum_and[n] = fSum_or[n] = fSum_xor[n] = a[n];
		for(int i = n-1;i >= 1; --i)
		{
			fSum_and[i] = fSum_and[i+1] & a[i];
			fSum_or[i] = fSum_or[i+1] | a[i];
			fSum_xor[i] = fSum_xor[i+1] ^ a[i];
		}
		
		while(p--)
		{
			scanf("%d",&pi);
			if(pi == 1)
				printf("%d %d %d\n",fSum_and[2], fSum_or[2], fSum_xor[2]);
			else if(pi == n)
				printf("%d %d %d\n",zSum_and[n-1], zSum_or[n-1], zSum_xor[n-1]);
			else
				printf("%d %d %d\n", zSum_and[pi-1]&fSum_and[pi+1], zSum_or[pi-1]|fSum_or[pi+1], zSum_xor[pi-1]^fSum_xor[pi+1]);
			
		}
	}
		
}
