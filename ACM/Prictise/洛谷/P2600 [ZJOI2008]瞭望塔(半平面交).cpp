#include <bits/stdc++.h>
using namespace std;
const double inf = 1e18;
const double eps = 1e-8;
const int maxp = 10005;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	void input() {//输入
		scanf("%lf%lf", &x, &y);
	}
	bool operator == (Point b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	//叉积
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
};

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	bool operator ==(Line v) {
		return (s == v.s)&&(e == v.e);
	}
	
	//`两向量平行(对应直线平行或重合)`
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s)) == 0;
	}
	
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
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
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator &(const Line &b)const {
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0,res);//两直线重合
			else return make_pair(1,res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2,res);//有交点
	}
	
	
};

struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n) {
		n = _n;
		for (int i = 0; i < n; i++)
			p[i].input();
	}
	
	void getline() {//通过顶点得到线段
		for (int i = 0; i < n; i++)
			l[i] = Line(p[i], p[(i + 1) % n]);
	}
};

struct halfplane: public Line {
	double angle;
	halfplane(){}
	// 表示向量s->e逆时针(左侧)的半平面
	halfplane(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	halfplane(Line v) {
		s = v.s;
		e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y,e.x-s.x);
	}
	bool operator < (const halfplane &b) const{
		return angle < b.angle;
	}
};

struct halfplanes {
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st,ed;
	void push(halfplane tmp) {
		hp[n++] = tmp;
	}
	//去重
	void unique() {
		int m = 1;
		for(int i = 1;i < n;i++){
			if(sgn(hp[i].angle-hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e-hp[m-1].s)^(hp[i].s-hp[m-1].s) ) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	
	bool halfplaneinsert(){
		for(int i = 0;i < n;i++) hp[i].calcangle();
		sort(hp,hp+n);
		unique();
		que[st=0] = 0;
		que[ed=1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2;i < n;i++){
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)st++;
			que[++ed] = i;
			if(hp[i].parallel(hp[que[ed-1]])) return false;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}
		
		while(st<ed && sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[que[st]].s))<0)ed--;
		while(st<ed && sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-hp[que[ed]].s))<0)st++;
		if(st+1 >= ed)return false;
		return true;
	}
	
	//`得到最后半平面交得到的凸多边形`
	//`需要先调用halfplaneinsert() 且返回true`
	void getconvex(polygon &con) {
		p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
		con.n = ed-st+1;
		for(int j = st,i = 0;j <= ed;i++,j++)
			con.p[i] = p[j];
	}
};

int n;
Point p[maxp];
halfplanes hf;
polygon res;

double solve() {
	double ans = 1e18;
	int m = res.n;
	
	for(int i = 0; i < n; i++) {
		Point now (p[i].x, inf);
		Line l (p[i], now);
		for(int j = 0; j < m; j++) {
			if(l.seg_cross_seg(res.l[j]) >= 1) {
				Point t = (l & res.l[j]).second;
				ans = min(ans, dist(p[i], t));
			}
		}
	}
	
	for(int i = 0; i < m; i++) {
		Point now (res.p[i].x, -inf);
		Line l (res.p[i], now);
		for(int j = 1; j < n; j++) {
			Line k (p[j-1], p[j]);
			if(l.seg_cross_seg(k) >= 1) {
				Point t = (l & k).second;
				ans = min(ans, dist(res.p[i], t));
			}
		}
	}
	
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lf", &p[i].x);
	for(int i = 0; i < n; i++) scanf("%lf", &p[i].y);
	hf.push(halfplane(Point(-inf, inf), Point(-inf, -inf)));
	hf.push(halfplane(Point(-inf, -inf), Point(inf, -inf)));
	hf.push(halfplane(Point(inf, -inf), Point(inf, inf)));
	hf.push(halfplane(Point(inf, inf), Point(-inf, inf)));
	for(int i = 1; i < n; i++) hf.push(halfplane(p[i-1], p[i]));
	
	hf.halfplaneinsert();
	hf.getconvex(res);
	res.getline();
	
	printf("%.3f\n", solve());
}