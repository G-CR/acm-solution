#include <iostream>
#include <queue>
using namespace std;

int l,r,c,sl,sr,sc,el,er,ec;
char mp[35][35][35];
bool vis[35][35][35];

int base[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

struct node{
	int f,x,y;
	int step;
	bool operator < (const node& a)const{
		return step > a.step;
	}
};

priority_queue <node> Q;

void bfs()
{
	node p;
	p.f = sl; p.x = sr; p.y = sc; p.step = 0;
	vis[sl][sr][sc] = 1;
	Q.push(p);
	while(!Q.empty())
	{
		node s = Q.top();
		Q.pop();
		if(s.f == el && s.x == er && s.y == ec)
		{
			printf("Escaped in %d minute(s).\n", s.step);
			return;
		}
		for(int i = 0;i < 6; i++)
		{
			int tl = s.f + base[i][0];
			int tr = s.x + base[i][1];
			int tc = s.y + base[i][2];
			if(mp[tl][tr][tc] != '#' && (tl>=1&&tl<=l) && (tr>=1&&tr<=r) && (tc>=1&&tc<=c) && !vis[tl][tr][tc])
			{
				node e;
				e.f = tl; e.x = tr; e.y = tc;
				e.step = s.step+1;
				vis[e.f][e.x][e.y] = 1;
				Q.push(e);
			}
		}
	}
	printf("Trapped!\n");	
}

int main() 
{
	while(cin >> l >> r >> c)
	{
		if(l == 0 && r == 0 && c == 0) return 0;
		for(int i = 1;i <= l; i++)
			for(int j = 1;j <= r; j++)
				for(int k = 1;k <= c; k++)
				{
					scanf(" %c", &mp[i][j][k]);
					if(mp[i][j][k] == 'S')
						sl = i,sr = j,sc = k;
					if(mp[i][j][k] == 'E')
						el = i,er = j,ec = k;
				}
		memset(vis,0,sizeof(vis));
		bfs();
	}
}