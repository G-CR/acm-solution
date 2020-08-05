#include <bits/stdc++.h>
using namespace std;
const int n = 1e4;
struct node{
	int x,y;
}poi[1005];

bool cmp(node a,node b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int T,N,i,ans1,ans2,ans3,ans4;

int main() 
{
	scanf("%d", &T);
	while(T--)
	{
		ans1 = ans2 = ans3 = ans4 = 0;
		scanf("%d", &N);
		for(i = 1;i <= N; i++)
		{
			scanf("%d %d", &poi[i].x, &poi[i].y);
		}
		sort(poi+1,poi+1+N,cmp);
		
		int m = N/2;
		double tx1,tx2,ty1,ty2;
		tx1 = poi[m].x; ty1 = poi[m].y;
		tx2 = poi[m+1].x; ty2 = poi[m+1].y;
		
		double mx = 0.5*(tx1+tx2);
		double my = 0.5*(ty1+ty2);
//		cout << "mx = " << mx << " my = " << my << endl;
		
		if(floor(mx) == floor(mx+0.6)) 
		{
			ans1 = mx-1; 
			ans2 = mx+1;
		}
		else 
		{
			ans1 = floor(mx); 
			ans2 = ans1+1;
		}
		
		if(floor(my) == floor(my+0.6))
		{
			ans3 = my+n; 
			ans4 = my-n;
		}
		else 
		{
			ans3 = floor(my)+1+n; 
			ans4 = floor(my)-n;
		}

		cout << ans1 << ' ' << ans3 << ' ' << ans2 << ' ' << ans4 << endl;
	}
	return 0;
}