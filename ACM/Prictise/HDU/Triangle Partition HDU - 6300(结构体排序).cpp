#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point { // 表示点
	int x, y;
	int id;
} p[3003];

bool cmp(Point p1, Point p2) {
	if(p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= 3*n; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
			p[i].id = i;
		}
		sort(p+1, p+1+3*n, cmp);
		
		for(int i = 1;i <= 3*n; i+=3) {
			printf("%d %d %d\n", p[i].id, p[i+1].id, p[i+2].id);
		}
	}
}