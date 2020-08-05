#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Point{
	int x,y,z;
}point[2002];
int n;
bool ok[2002];

double dist(struct Point* p1, struct Point* p2) {
	return sqrt(pow((p1->x-p2->x),2) + pow((p1->y-p2->y),2) + pow((p1->z-p2->z),2));
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].z);
	}
	
	double mindist = inf;
	int minnum;
	for(int i = 1;i <= n; i++) {
		if(ok[i]) continue;
		mindist = inf;
		for(int j = 1;j <= n; j++) {
			if(i == j || ok[j]) continue;
			double t = dist(&point[i], &point[j]);
			if(mindist > t) {
				minnum = j;
				mindist = t;
			}
		}
		ok[i] = ok[minnum] = 1;
		printf("%d %d\n", i, minnum);
	}
}