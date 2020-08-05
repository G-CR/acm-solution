#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;

ll n,ans,now;
queue <ll> q;

void bfs(ll n)
{
	while(!q.empty()) q.pop();
	q.push(1);
	
	while(!q.empty())
	{
		now = q.front(); q.pop();
		
		if(now % n == 0) {ans = now; break;}
		q.push(now*10);
		q.push(now*10+1);
	}
	return;
}

int main() 
{
	while(cin >> n && n)
	{
		bfs(n);
		printf("%lld\n",ans);
	}
	return 0;
}