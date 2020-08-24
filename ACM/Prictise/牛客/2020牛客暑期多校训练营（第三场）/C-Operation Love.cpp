#include <bits/stdc++.h>
using namespace std;

int _;
struct Point{
	double x,y;
}p[30];

double polygonarea()
{
	int i,j;
	double area = 0;
	for(i = 0;i < 20;++i){
		j = (i+1)%20;
		area += p[i].x*p[j].y;
		area -= p[i].y*p[j].x;
	}
	return area;
}

double len(int p1, int p2) {
	p1 %= 20; p2 %= 20;
	return (p[p1].x-p[p2].x)*(p[p1].x-p[p2].x)+(p[p1].y-p[p2].y)*(p[p1].y-p[p2].y);
}

bool nice(double len, double should) {
	if(fabs(len-should) < 1e-4) return 1;
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		for(int i = 0;i < 20; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		int dir = polygonarea()>0?1:-1;
		for(int i = 0;i < 20; i++) {
			if(nice(len(i,i+1),64)&&nice(len(i+1,i+2),81)&&nice(len(i+2,i+3),36)) {
				printf("%s\n", dir==1?"left":"right");
				break;
			}
			if(nice(len(i,i+1), 36)&&nice(len(i+1,i+2), 81)&&nice(len(i+2,i+3), 64)) {
				printf("%s\n", dir==1?"right":"left");
				break;
			}
		}
	}
}