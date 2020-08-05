#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct node{
	int p,num;
	node(){}
	node(int a,int b)
	{
		p = a; num = b;
	}
};

bool a[10000],vis[10000];
int x,y,ans,ok;
queue <node> q;

void sx()
{
	for(int i = 1;i <= 9999;i++)
		{a[i] = 1; if(a[i] % 2 == 0) a[i] = 0;} 
	for(int i = 2;i <= 9999; i++) if(a[i])
		for(int j = i*2; j <= 9999; j += i) a[j] = 0;
		
//	for(int i = 1000;i <= 9999; i++) if(a[i]) cout << i << " ";
}

bool is(int n)
{
	if(a[n]) return 1;
	return 0;
}

void bfs()
{
	while(!q.empty()) q.pop();
	q.push(node(x,0));
	vis[x]=1;
	
	while(!q.empty())
	{
		ok = 0;
		node now = q.front();
		q.pop();
		if(now.p == y) {ok = 1;ans = now.num; break;}
		int t[5];
		t[1] = now.p/1000; t[2] = now.p%1000/100;
		t[3] = now.p%100/10; t[4] = now.p%10;
//		cout << "t= " << t[1] << t[2] << t[3] << t[4] << endl;
		for(int i = 1;i <= 4; i++)
		{
			int tmp = t[i];
			for(int j = 0; j <= 9; j++)
			{
				if((j == 0 && i == 1) || tmp == j) continue;
				t[i] = j;
				int change = t[1]*1000 + t[2]*100 + t[3]*10 + t[4];
				if(is(change) && change < 9999 && change > 1000 && !vis[change] )
				{
					q.push(node(change,now.num+1));
					vis[change] = 1;
				}
			}
			t[i] = tmp;
		}
	}
	
}

int main() 
{
	int t;
	sx();
	scanf("%d", &t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d %d", &x, &y);
		bfs();
		if(ok) cout << ans << endl;
		else puts("Impossible");
	}
	
}