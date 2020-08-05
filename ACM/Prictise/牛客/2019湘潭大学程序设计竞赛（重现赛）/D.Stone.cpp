//https://ac.nowcoder.com/acm/contest/893/D
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
int T,n,i;
long long a[10007],Max,Maxl,Maxr,Maxa,Min,t;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		Max = Maxl = Maxr = Maxa = Min = 0;
		scanf("%d",&n);
		
		for(i = 1;i <= n; ++i)
		{
			scanf("%lld",&a[i]);
			if(Maxa < a[i]);
				Max = i;
		}
		
		if(n == 1)
		{
			printf("0");
			return 0;
		}
		
		if(Max == n)
		{
			for(i = 1;i <= n - 1; ++i)
				Min += a[i];
		}
		
		else if(Max == 1)
		{
			for(i = 2;i <= n; ++i)
				Min += a[i];
		}
		
		else
		{
			for(i = 1;i <= n; ++i)
			{
				if(i < Max)
					Maxl += a[i];
				if(i > Max)
					Maxr += a[i];
			}
			
			if(Maxl <= Maxr)
				t = Maxl;
			else
				t = Maxr;
				
			if(Maxl + Maxr < a[Max] + t)
				Min = Maxl + Maxr;
			else if(Maxl < Maxr)
				Min = Maxl + a[Max];
			else
				Min = Maxr + a[Max];
			
		}
			
		printf("%lld\n",Min);
		
	}
}
