#include <iostream>
#include <stack>
using namespace std;
const int N = 2e5+10;
int n,i,a[N],Max,t,l,r;
stack <int> q;
 
int main()
{
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(Max < a[i]) Max = a[i],t = i;
	}
	q.push(a[t]);
	
	l = t - 1, r = t + 1;
	while((q.top() > a[l] && q.top() > a[r]))
	{
		if(a[l] > a[r]) q.push(a[l--]);
		else q.push(a[r++]);
	}
 
//	while(!q.empty()) {cout << q.top() << " "; q.pop();}
	if(q.size()-1 == n) puts("YES");
	else puts("NO");
}