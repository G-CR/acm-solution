#include<stdio.h>

int x,y,n,countl,i;
char a[200005],b[200005];

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	for(i = 0;i <= n; i++)
		scanf("%c",&a[i]);
	
	int j = 1;
	for(i = n-x; i <= n; i++)
		b[j++] = a[i];
		
	if(b[x-y+1] == '0') countl++;
	for(i = 2;i <= x+1; i++)
	{	
		if(b[i] != '0' && i != x-y+1)
		{
//			printf("i = %d ",i);
			countl++;
		}
			
	}
	
	printf("%d\n",countl);
	
}
