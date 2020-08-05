#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = 1e7;
int Map[N][N],dist[N],n,m;
int flag[N];

struct node{
	int u,step;
	node(){}
	node(int a,int sp)
	{
		u = a;step = sp;
	}
	bool operator < (const node& a)const{
		return step > a.step;
	}
};

void dijkstra(int st)
{
	priority_queue <node> Q;
	Q.push(node(st,0));
	memset(flag, 0, sizeof(flag));
	for(int i = 1;i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;
	while(!Q.empty())
	{
		node it = Q.top();
		Q.pop();
		int t = it.u;
		if(flag[t])
			continue;
		flag[t] = 1;
		for(int i = 1;i <= n; i++)
		{
			if(!flag[i] && Map[t][i] < INF)
			{
				if(dist[i] > dist[t] + Map[t][i])
				{
					dist[i] = dist[t] + Map[t][i];
					Q.push(node(i,dist[i]));
				}
			}
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
	dijkstra(st);
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
7
1 2 2
1 3 3
2 3 5
2 4 6
3 4 7
3 5 1
4 5 4
1
*/