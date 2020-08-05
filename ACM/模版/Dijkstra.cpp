#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e7;
int Map[N][N],dist[N],p[N],n,m;
bool flag[N];

void Dijkstra(int u)
{
	for(int i = 1;i <= n; i++)
	{
		dist[i] = Map[u][i];
		flag[i] = 0;
		if(dist[i] == INF) p[i] = -1;
		else p[i] = u;
	}
	
	dist[u] = 0,flag[u] = 1;
	for(int i = 1;i <= n; i++)
	{
		int temp = INF,t = u;
		for(int j = 1;j <= n; j++)
			if(!flag[j] && dist[j] < temp)
			{
				t = j;
				temp = dist[j];
			}
		if(t == u) return;
		flag[t] = 1;
		for(int j = 1;j <= n; j++)
			if(!flag[j] && Map[t][j] < INF)
				if(dist[j] > (dist[t]+Map[t][j]))
				{
					dist[j] = dist[t] + Map[t][j];
					p[j] = t;
				}
	}
}

int main() 
{
	int u,v,w,st;
	cout << "请输入城市的个数:" << endl;
	cin >> n;
	cout << "请输入城市之间的路线的个数:" << endl;
	cin >> m;
	cout << "请输入城市之间的路线以及距离:" << endl;
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= n; j++)
		{
			Map[i][j] = INF;
		}
	while(m--)
	{
		cin >> u >> v >> w;
		Map[u][v] = min(Map[u][v],w);
	}
	cout << "请输入小明所在的位置:" << endl;
	cin >> st;
	Dijkstra(st);
	for(int i = 1;i <= n; i++)
	{
		if(i == st) continue;
		cout << "小明:" << st << "-" << "要去的位置:" << i << endl;
		if(dist[i] == INF)
			cout << "sorry,无路可达" << endl;
		else
			cout << "最短距离为:" << dist[i] << endl;
 	}
	return 0;
}
/*
5
11
1 5 12
5 1 8
1 2 16
2 1 29
5 2 32
2 4 13
4 2 27
1 3 15
3 1 21
3 4 7
4 3 19
1
*/