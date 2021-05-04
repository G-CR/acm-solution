//https://vjudge.net/contest/432769#problem/C
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxp = 1000;

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
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	bool operator == (Point b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b)const{
		return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x;
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	//叉积
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
	//点积
	double operator *(const Point &b)const{
		return x*b.x + y*b.y;
	}
	//返回长度
	double len(){
		return hypot(x,y);//库函数
	}
	//返回长度的平方
	double len2(){
		return x*x + y*y;
	}
	//返回两点的距离
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	Point operator +(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const double &k)const{
		return Point(x*k,y*k);
	}
	Point operator /(const double &k)const{
		return Point(x/k,y/k);
	}
	//`计算pa  和  pb 的夹角`
	//`就是求这个点看a,b 所成的夹角`
	//`测试 LightOJ1203`
	double rad(Point a,Point b) {
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	//`化为长度为r的向量`
	Point trunc(double r){
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	//`逆时针旋转90度`
	Point rotleft(){
		return Point(-y,x);
	}
	//`顺时针旋转90度`
	Point rotright(){
		return Point(y,-x);
	}
	//`绕着p点逆时针旋转angle`
	Point rotate(Point p,double angle){
		Point v = (*this) - p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};
double dist(Point a, Point b) {
	return ((b-a) * (b-a));
}

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	bool operator ==(Line v) {
		return (s == v.s)&&(e == v.e);
	}
	//`根据一个点和倾斜角angle确定直线,0<=angle<pi`
	Line(Point p,double angle){
		s = p;
		if(sgn(angle-PI/2) == 0){
			e = (s + Point(0,1));
		}
		else{
			e = (s + Point(1,tan(angle)));
		}
	}
	//ax+by+c=0
	Line(double a,double b,double c){//ax+by+c=0
		if(!sgn(a)){
			s=Point(0,-c/b),e=Point(1,-c/b);
			if(sgn(b)>0)adjust();   // 保证点是逆时针 有时候需要变号
		}
		else if(!sgn(b)){
			s=Point(-c/a,0),e=Point(-c/a,1);
			if(sgn(a)<0)adjust();
		}
		else{
			s=Point(0,-c/b),e=Point(1,(-c-a)/b);
			if(sgn(b)>0)adjust();
		}
	}
	void input(){
		s.input();
		e.input();
	}
	void adjust(){
		if(e < s)swap(s,e);
	}
	//求线段长度
	double length(){
		return s.distance(e);
	}
	//`返回直线倾斜角 0<=angle<pi`
	double angle(){
		double k = atan2(e.y-s.y,e.x-s.x);
		if(sgn(k) < 0)k += PI;
		if(sgn(k-PI) == 0)k -= PI;
		return k;
	}
	//`点和直线关系`
	//`1  在左侧`
	//`2  在右侧`
	//`3  在直线上`
	int relation(Point p){
		int c = sgn((p-s)^(e-s));
		if(c < 0)return 1;
		else if(c > 0)return 2;
		else return 3;
	}
	// 点在线段上的判断
	bool pointonseg(Point p){
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
	}
	//`两向量平行(对应直线平行或重合)`
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s)) == 0;
	}
	//`两线段相交判断`
	//`2 规范相交`
	//`1 非规范相交`
	//`0 不相交`
	int segcrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if( (d1^d2)==-2 && (d3^d4)==-2 )return 2;
		return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
		(d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
		(d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
		(d4==0 && sgn((e-v.s)*(e-v.e))<=0);
	}
	//`直线和线段相交判断`
	//`-*this line   -v seg`
	//`2 规范相交`
	//`1 非规范相交`
	//`0 不相交`
	int linecrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		if((d1^d2)==-2) return 2;
		return (d1==0||d2==0);
	}
	//`两直线关系`
	//`0 平行`
	//`1 重合`
	//`2 相交`
	int linecrossline(Line v){
		if((*this).parallel(v))
			return v.relation(s)==3;
		return 2;
	}
	//`求两直线的交点`
	//`要保证两直线不平行或重合`
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	//点到直线的距离
	double dispointtoline(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	//点到线段的距离
	double dispointtoseg(Point p){
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
			return min(p.distance(s),p.distance(e));
		return dispointtoline(p);
	}
	//`返回线段到线段的距离`
	//`前提是两线段不相交，相交距离就是0了`
	double dissegtoseg(Line v){
		return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
	}
	//`返回点p在直线上的投影`
	Point lineprog(Point p){
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	//`返回点p关于直线的对称点`
	Point symmetrypoint(Point p){
		Point q = lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
	
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

struct Vector: public Point {
	Vector(){}
	Vector(double a,double b) {
		x=a;    y=b;
	}
	Vector(Point _a,Point _b) { //a->b
		double dx=_b.x-_a.x;
		double dy=_b.y-_a.y;
		x=dx;   y=dy;
	}
	Vector(Line v) {
		double dx=v.e.x-v.s.x;
		double dy=v.e.y-v.s.y;
		x=dx;   y=dy;
	}
	double length() {
		return (sqrt(x*x+y*y));
	}
	Vector Normal() { //返回this的单位长度的法向量
		double L=sqrt(x*x+y*y);
		Vector Vans=Vector(-y/L,x/L);
		return Vans;
	}
};

struct circle{
	Point p;//圆心
	double r;//半径
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
		
	bool operator == (circle v){
		return (p==v.p) && sgn(r-v.r)==0;
	}
	bool operator < (circle v)const{
		return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
	}
	//面积
	double area(){
		return PI*r*r;
	}
	
	//`点和圆的关系`
	//`0 圆外`
	//`1 圆上`
	//`2 圆内`
	int relation(Point b){
		double dst = b.distance(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r)==0)return 1;
		return 0;
	}
	
	//`直线和圆的关系`
	//`比较的是圆心到直线的距离和半径的关系`
	int relationline(Line v){
		double dst = v.dispointtoline(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r) == 0)return 1;
		return 0;
	}
	
	
	//`求直线和圆的交点，返回交点个数`
	int pointcrossline(Line v,Point &p1,Point &p2){
		if(!(*this).relationline(v))return 0;
		Point a = v.lineprog(p);
		double d = v.dispointtoline(p);
		d = sqrt(r*r-d*d);
		if(sgn(d) == 0){
			p1 = a;
			p2 = a;
			return 1;
		}
		p1 = a + (v.e-v.s).trunc(d);
		p2 = a - (v.e-v.s).trunc(d);
		return 2;
	}
	
	
	//`求圆和三角形pab的相交面积`
	//`测试：POJ3675 HDU3982 HDU2892`
	double areatriangle(Point a,Point b){
		if(sgn((p-a)^(p-b)) == 0)return 0.0;
		Point q[5];
		int len = 0;
		q[len++] = a;
		Line l(a,b);
		Point p1,p2;
		if(pointcrossline(l,q[1],q[2])==2){
			if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1];
			if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2];
		}
		q[len++] = b;
		if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q[2]);
		double res = 0;
		for(int i = 0;i < len-1;i++){
			if(relation(q[i])==0||relation(q[i+1])==0){
				double arg = p.rad(q[i],q[i+1]);
				res += r*r*arg/2.0;
			}
			else{
				res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
			}
		}
		return res;
	}
};



struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void add(Point q) {
		p[n++] = q;
	}
	void input(int _n){
		n = _n;
		for(int i = 0;i < n;i++)
			p[i].input();
	}
	struct cmp{
		Point p;
		cmp(const Point &p0){p = p0;}
		bool operator()(const Point &aa,const Point &bb){
			Point a = aa, b = bb;
			int d = sgn((a-p)^(b-p));
			if(d == 0){
				return sgn(a.distance(p)-b.distance(p)) < 0;
			}
			return d > 0;
		}
	};
	
	void norm(){
		Point mi = p[0];
		for(int i = 1;i < n;i++)mi = min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}
	
	void getconvex(polygon &convex){
		sort(p,p+n);
		convex.n = n;
		for(int i = 0;i < min(n,2);i++){
			convex.p[i] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		if(n <= 2)return;
		int &top = convex.n;
		top = 1;
		for(int i = 2;i < n;i++){
			while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		int temp = top;
		convex.p[++top] = p[n-2];
		for(int i = n-3;i >= 0;i--){
			while(top != temp && sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		convex.norm();//`原来得到的是顺时针的点，排序后逆时针`
	}
	
	double areacircle(circle c){
		double ans = 0;
		for(int i = 0;i < n;i++){
			int j = (i+1)%n;
			if(sgn( (p[j]-c.p)^(p[i]-c.p) ) >= 0)
				ans += c.areatriangle(p[i],p[j]);
			else ans -= c.areatriangle(p[i],p[j]);
		}
		return fabs(ans);
	}
};

double r;
polygon p, now;
Point cen, q[4];
Vector v;
const double inf=100;
pair<int,int> ma[4]={{0,2},{2,1},{1,3},{3,0}};
int main() {
	scanf("%lf", &r);
	circle c (Point(0,0), r);
	p.input(4);
	
	v = (Line(p.p[0], p.p[1]));
	
	Point o = v * inf;
	q[0] = p.p[0]-o;
	
	v = (Line(p.p[1], p.p[0]));
	o = v * inf;
	q[1] = p.p[1]-o;
	
	v = (Line(p.p[2], p.p[3]));
	o = v * inf;
	q[2] = p.p[2]-o;
	
	v = (Line(p.p[3], p.p[2]));
	o = v * inf;
	q[3] = p.p[3]-o;
	
	p.n = 0;
	for(int i = 0; i < 4; i++) p.add(q[i]);
	
	Line l1 = Line(p.p[0], p.p[1]);
	Line l2 = Line(p.p[2], p.p[3]);
	Point cen = (l1 & l2).second;
	double ans = -1.0;
	polygon k;
	for(int i = 0; i < 4; i++) {
		k.n = 0;
		int p1=ma[i].first;
		int p2=ma[i].second;
		Point u = p.p[p1], v = p.p[p2];
		k.add(u); k.add(cen); k.add(v);
		polygon res; k.getconvex(res);
		ans = max(ans, res.areacircle(c));
	}
	
	printf("%.10f\n", ans);
}