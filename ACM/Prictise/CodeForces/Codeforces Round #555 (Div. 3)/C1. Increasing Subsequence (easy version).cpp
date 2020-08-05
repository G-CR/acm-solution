#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],cnt;
char s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int p=1,q=n,x=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	while(p<=q)
	{
		if(a[p]<a[q])
		{
			if(a[p]>x)
			{
				s[++cnt]='L';
				x=a[p++];
			}
			else if(a[q]>x)
			{
				s[++cnt]='R';
				x=a[q--];
			}
			else break;
		}
		else
		{
			if(a[q]>x)
			{
				s[++cnt]='R';
				x=a[q--];
			}
			else if(a[p]>x)
			{
				s[++cnt]='L';
				x=a[p++];
			}
			else break;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	printf("%c",s[i]);
}
