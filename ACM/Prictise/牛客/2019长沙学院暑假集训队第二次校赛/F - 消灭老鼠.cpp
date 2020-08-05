#include <bits/stdc++.h>
using namespace std;
const int R = 1412;
int T,n,pos[1003],t;

int main() 
{
	scanf("%d", &T);
	while(T--)
	{
		int sum = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) scanf("%d", &pos[i]);
		sort(pos+1,pos+1+n);
		
		int now;
		for(int i = 1;i <= n-1; i++)
		{
			sum++;
			now = pos[i]+R;
			while(now + R >= pos[i+1] && i <= n-1) i++;
		}
		if(pos[n] - now > R) sum++;
		printf("%d\n", sum);
	}	
}