#include <iostream>
#include <queue>
using namespace std;

int n,k,ans;
bool mp[1000000];
struct node{
	int loc,step;
	bool operator < (const node& a) const{
		return step > a.step;
	}	
};

priority_queue<node> q;

void bfs()
{
	node a;
	a.loc = n; a.step = 0;
	q.push(a);
	while(!q.empty())
	{
		node t = q.top();
		q.pop();
		if(t.loc == k) {ans = t.step; break;}
		int tl = t.loc-1;
		if(tl >=0 && !mp[tl])
		{
			node s;
			s.loc = tl;
			s.step = t.step+1;
			mp[s.loc] = 1;
			q.push(s);
		}
		tl = t.loc+1;
		if(tl<=200000 && !mp[tl])
		{
			node s;
			s.loc = tl;
			s.step = t.step+1;
			mp[s.loc] = 1;
			q.push(s);
		}
		tl = t.loc*2;
		if(tl<=200000 && !mp[tl])
		{
			node s;
			s.loc = tl;
			s.step = t.step+1;
			mp[s.loc] = 1;
			q.push(s);
		}
	}
	cout << ans << endl;
}

int main() 
{
	scanf("%d %d", &n, &k);
	memset(mp,0,sizeof(mp));
	mp[n] = 1;
	bfs();
}