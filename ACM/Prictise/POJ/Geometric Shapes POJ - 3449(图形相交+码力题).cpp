#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define eps 1e-8

double sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point { // 表示点
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
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
};


int cnt = 0;

struct Node {
	char id;
	int dian;
	Point p[30];
} node[30];


int inputs() {
	char id;
	scanf(" %c", &id);
	if(id == '-') return -1;
	else if(id == '.') return -2;
	node[cnt].id = id;
	
	string type;
	cin >> type;
	// square rectangle line triangle  polygon
	if(type == "line") {
		node[cnt].dian = 2;
		scanf(" (%lf,%lf)", &node[cnt].p[0].x, &node[cnt].p[0].y);
		scanf(" (%lf,%lf)", &node[cnt].p[1].x, &node[cnt].p[1].y);
	}
	else if(type == "triangle") {
		node[cnt].dian = 3;
		scanf(" (%lf,%lf)", &node[cnt].p[0].x, &node[cnt].p[0].y);
		scanf(" (%lf,%lf)", &node[cnt].p[1].x, &node[cnt].p[1].y);
		scanf(" (%lf,%lf)", &node[cnt].p[2].x, &node[cnt].p[2].y);
	}
	else if(type == "rectangle") {
		node[cnt].dian = 4;
		scanf(" (%lf,%lf)", &node[cnt].p[0].x, &node[cnt].p[0].y);
		scanf(" (%lf,%lf)", &node[cnt].p[1].x, &node[cnt].p[1].y);
		scanf(" (%lf,%lf)", &node[cnt].p[2].x, &node[cnt].p[2].y);
		node[cnt].p[3].x = node[cnt].p[0].x + node[cnt].p[2].x - node[cnt].p[1].x;
		node[cnt].p[3].y = node[cnt].p[0].y + node[cnt].p[2].y - node[cnt].p[1].y;
	}
	else if(type == "square") {
		node[cnt].dian = 4;
		scanf(" (%lf,%lf)", &node[cnt].p[0].x, &node[cnt].p[0].y);
		scanf(" (%lf,%lf)", &node[cnt].p[2].x, &node[cnt].p[2].y);
		node[cnt].p[1].x = (node[cnt].p[0].x - node[cnt].p[0].y + node[cnt].p[2].x + node[cnt].p[2].y) / 2;
		node[cnt].p[1].y = (node[cnt].p[0].x + node[cnt].p[0].y - node[cnt].p[2].x + node[cnt].p[2].y) / 2;
		node[cnt].p[3].x = (node[cnt].p[0].x + node[cnt].p[0].y + node[cnt].p[2].x - node[cnt].p[2].y) / 2;
		node[cnt].p[3].y = (-node[cnt].p[0].x + node[cnt].p[0].y + node[cnt].p[2].x + node[cnt].p[2].y) / 2;
	}
	else {
		scanf("%d", &node[cnt].dian);
		for(int i = 0;i < node[cnt].dian; i++) {
			scanf(" (%lf,%lf)", &node[cnt].p[i].x, &node[cnt].p[i].y);
		}
	}
	cnt++;
	
	return 0;
}

bool cmp(Node a, Node b) {
	return a.id < b.id;
}

bool check(int a, int b) {
	for(int i = 0;i < node[a].dian; i++) {
		for(int j = 0;j < node[b].dian; j++) {
			Line l1 = Line(node[a].p[i], node[a].p[(i+1)%node[a].dian]);
			Line l2 = Line(node[b].p[j], node[b].p[(j+1)%node[b].dian]);
			if(l1.seg_cross_seg(l2)) return 1;
		}
	}
	return 0;
}


int main() {
	while(1) {
		int bye;
		cnt = 0;
		while(1) {bye = inputs(); if(bye == -1 || bye == -2) break;}
		if(bye == -2) break;
		sort(node, node+cnt, cmp);
				
		for(int i = 0; i < cnt; i++) {
			printf("%c ", node[i].id);
			int num = 0;
			vector <int> pos; pos.clear();
			
			for(int j = 0; j < cnt; j++) {
				if(i != j && check(i, j)) {
					num++;
					pos.push_back(j);
				}
			}
			if(num == 0) puts("has no intersections");
			else if(num == 1) {
				printf("intersects with %c\n", node[pos[0]].id);
			}
			else if(num == 2) {
				printf("intersects with %c and %c\n", node[pos[0]].id, node[pos[1]].id);
			}
			else {
				printf("intersects with");
				for(int i = 0;i < pos.size(); i++) {
					if(i == pos.size()-1) printf(" and %c\n", node[pos[i]].id);
					else printf(" %c,", node[pos[i]].id);
				}
			}
		}
		puts("");
	}
}