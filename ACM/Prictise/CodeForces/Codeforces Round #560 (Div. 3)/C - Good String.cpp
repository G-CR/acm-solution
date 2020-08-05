#include<bits/stdc++.h>

char a[200007];
int m,n,i,count;
int main()
{
	scanf("%d",&n);
	getchar();
	for(i = 1;i <= n; i++)
		scanf("%c",&a[i]);
		
	for(i = 1;i < n; i++)
	{
		if(a[i] == a[i+1])
		{
			a[i] = '0';
			m++;
		}
		else
		{
			i++;
		}
	}
	
	for(i = 1;i <= n; i++)
	{
		if(a[i] != '0')
			count++;
		
	}
//	printf("\ncount = %d\n",count);
	if(count % 2 == 1)
	{
		a[n] = '0';
		m++;
	}
	
	printf("%d\n",m);
	for(i = 1;i <= n; i++)
	{
		if(a[i] == '0')
			continue;
		printf("%c",a[i]);
	}
	printf("\n");
	
}
