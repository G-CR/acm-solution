#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y, z, id;
}p[50004];
int n;
bool ok[50004];
vector <point> vc;

bool cmp(point a, point b) {
	if(a.x != b.x) return a.x < b.x;
	else {
		if(a.y != b.y) return a.y < b.y;
		else return a.z < b.z;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		p[i].id = i;
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
	}
	sort(p+1, p+1+n, cmp);
	
	for(int i = 1;i < n; i++) {
		if(p[i].x == p[i+1].x && p[i].y == p[i+1].y) {
			printf("%d %d\n", p[i].id, p[i+1].id);
			ok[p[i].id] = ok[p[i+1].id] = 1;
			i++;
		}
	}
	
	for(int i = 1;i <= n; i++) {
		if(!ok[p[i].id]) vc.push_back(p[i]);
	}
	
	for(int i = 0;i < vc.size(); i++) {
		if(vc[i].x == vc[i+1].x && (!ok[vc[i].id] && !ok[vc[i+1].id])) {
			printf("%d %d\n", vc[i].id, vc[i+1].id);
			ok[vc[i].id] = ok[vc[i+1].id] = 1;
			i++;
		}
	}
	
	for(int i = 0, j = 0;i < vc.size() && j < vc.size();) {
		if(i == j) {
			j++; continue;
		}
		if(!ok[vc[i].id] && !ok[vc[j].id]) {
			printf("%d %d\n", vc[i].id, vc[j].id);
			ok[vc[i].id] = ok[vc[j].id] = 1;
			i++; j++;
		}
		else if(ok[vc[i].id]) i++;
		else if(ok[vc[j].id]) j++;
	}
}