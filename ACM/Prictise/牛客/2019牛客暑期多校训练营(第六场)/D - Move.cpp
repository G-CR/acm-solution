#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t,p,n,k;
int a[1005];

bool ok(int v)
{
	multiset <int> q;
	for(int i=1;i<=n;i++) q.insert(a[i]);
	
	multiset<int>::iterator it;
	
//	for(it = q.begin();it != q.end();it++)
//		cout << *it << " ";
//	cout << endl;
	
	for(int i = 1;i <= k; i++)
		{
			int w = v;
			while(w)
			{
				it = q.upper_bound(w);
				if(it == q.begin()) break;
				it--;
				w -= *it;
				q.erase(it);
				if(q.empty()) return 1;
			}
		}
		return 0;
}

int main() 
{
	
	scanf("%d", &t);
	for(p = 1;p <= t; p++)
	{
		int sum = 0;
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
				
		int low = sum / k;
		if(sum % k) low++;
		
		 for(int i = low;;i++)
		{
			if(ok(i))
			{
				printf("Case #%d: %d\n", p, i);
				break;
			}
		}	
	}
}