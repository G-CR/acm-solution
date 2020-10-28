## The Doors [POJ - 1556](https://vjudge.net/problem/POJ-1556/origin)

题意：给一个框，框里面有n道墙，每堵墙都有两个缺口（缺口保证不在边界处），从框的最左边的中间到最右边的中间最少需要做多远？

思路：把每一个点处理出来，然后把能够直接到的点用边都连接起来，也就是两个点之间没有墙挡着就行，也就是两点连线没有线段与之规范相交。拿这些边跑一边最短路就完了。

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = 1e20;
const int maxn = 1010;
int sgn(double x){
	if(fabs(x)<0)return 0;
	if(x<0)return -1;
	else return 1;
}
struct Point {
	double x,y;
	Point(){};
	Point(double _x,double _y){
		x=_x;y=_y;
	}
	Point operator - (const Point &b)const{
		return Point (x-b.x,y-b.y);
	}
	//叉乘
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;
	}
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	double distance (Point b){
		return hypot(x-b.x,y-b.y);
	}
};
//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}
struct Line{
	Point s,e;
	Line(){};
	Line(Point _s,Point _e){
		s=_s;e=_e;
	}
	Line(double x1,double y1,double x2,double y2){
		s.x=x1;s.y=y1;e.x=x2;e.y=y2;
	}
	//线段与线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
			   (d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
			   (d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
			   (d4==0 &&sgn((e-v.s)*(e-v.e))<=0);
	}
	int relation(Point p){
		int c=sgn((p-s)^(p-e));
		if(c<0)return 1;
		else if(c>0) return 2;
		else return 3;
	}
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
	//直线与直线相交判断
	//0 平行
	//1 重合
	//2 相交
	int line_cross_line(Line v){
		if((*this).parallel(v))
		return v.relation(s)==3;
		return 2;
	}
};
struct edge{
	int ss,ee;
	double w;
	int next;
};
struct qnode{
	double dist;
	int num;
	bool operator < (const qnode &b)const{
		return dist>b.dist;
	}
};
edge e[maxn*maxn];
double dis[maxn];
int vis[maxn];
Point p[maxn];
Line s[maxn];
int head[maxn];
int cnt;
void add_edge(int ss,int ee,double ww){
	e[++cnt].ss=ss;e[cnt].ee=ee;e[cnt].w=ww;e[cnt].next=head[ss];head[ss]=cnt;
}
double dijkstra(int ss,int ee){
	priority_queue<qnode>q;
	qnode now,temp;
	dis[ss]=0;
	vis[ss]=1;
	now.dist=dis[ss];
	now.num=ss;
	q.push(now);
	while(!q.empty()){
		now=q.top();
		q.pop();
		vis[now.num]=0;
		for(int i=head[now.num];i!=-1;i=e[i].next){
			if(dis[e[i].ee]>now.dist+e[i].w){
				dis[e[i].ee]=now.dist+e[i].w;
				if(!vis[e[i].ee]){
					temp.dist=dis[e[i].ee];
					temp.num=e[i].ee;
					q.push(temp);
					vis[e[i].ee]=1;
				}
			}
		}
	}
	return dis[ee];
}
int main(){
	int n;
	while (~scanf("%d",&n)&&n!=-1){
		cnt=0;
		fill(dis,dis+maxn,inf);
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		int p_cnt=0,s_cnt=0;
		
		for(int i=0;i<n;i++){
			double x,y[4];
			scanf("%lf%lf%lf%lf%lf",&x,&y[0],&y[1],&y[2],&y[3]);
			for(int j=0;j<4;j++){
				p[p_cnt++]=Point(x,y[j]);
			}
			s[s_cnt++]=Line(x,0,x,y[0]);
			s[s_cnt++]=Line(x,y[1],x,y[2]);
			s[s_cnt++]=Line(x,y[3],x,10.0);
		}
		p[p_cnt++]=Point (10.0,5.0);
		p[p_cnt++]=Point (0.0,5.0);
		
		for(int i=0;i<p_cnt;i++){
			for(int j=0;j<p_cnt;j++){
				Line temp=Line(p[i],p[j]);
				int flag=0;
				for(int k=0;k<s_cnt;k++){
					if(temp.seg_cross_seg(s[k])==2){
						flag=1;
						break;
					}
					if(temp.seg_cross_seg(s[k])==1){ 
						if(temp.line_cross_line(s[k])==1){
							flag=1;
							break;
						}
					}
				}
				//cout<<i<<" "<<j<<" "<<flag<<" "<<g<<endl;
				if(!flag){
					add_edge(i,j,dist(p[i],p[j]));
					//cout<<e[cnt].ss<<" "<<e[cnt].ee<<" "<<e[cnt].w<<endl;
					add_edge(j,i,dist(p[i],p[j]));
					//cout<<e[cnt].ss<<" "<<e[cnt].ee<<" "<<e[cnt].w<<endl;
				}
			}
		}
		
		double ans = dijkstra(p_cnt-2,p_cnt-1);
		printf("%.2f\n",ans);
	}
	return 0;
}
```

