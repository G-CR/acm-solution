#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int id;
	int c, m, e;
	int sum;
} p[305];

bool cmp(node a, node b) {
	if(a.sum == b.sum) {
		if(a.c == b.c) {
			return a.id < b.id;
		}
		return a.c > b.c;
	}
	return a.sum > b.sum;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		p[i].id = i;
		scanf("%d %d %d", &p[i].c, &p[i].m, &p[i].e);
		p[i].sum = p[i].c + p[i].m + p[i].e;
	}
	sort(p+1, p+1+n, cmp);
	
	for(int i = 1;i <= 5; i++) {
		printf("%d %d\n", p[i].id, p[i].sum);
	}
}