#include<bits/stdc++.h>
using namespace std;

int n,countl = 0;
int a[200005];

int main()
{	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	
	int j = 1;
	for(int i = 1;i <= n; i++)
	{
		if(a[i] >= j)
		{		
			countl++;
			j++;
		}
	}
	printf("%d\n",countl);
}
