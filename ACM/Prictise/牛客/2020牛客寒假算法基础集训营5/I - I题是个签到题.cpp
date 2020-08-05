#include <bits/stdc++.h>
using namespace std;

int n, m;
struct node{
	int people;
	int num;
}a[20];

bool cmp(node a, node b) {
	return a.people > b.people;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i].people);
		a[i].num = i;
	}
	sort(a+1, a+1+n, cmp);
	
	double ans1 = 0;
	bool ans2 = 0;
	int pos, peo;
	for(int i = 1;i <= n; i++) {
		if(a[i].num == 9) {
			ans1 = ((double)(a[i].people))/((double)(m));
			pos = i;
			peo = a[i].people;
			break;
		}
	}
	
	int num = 1;
	for(int i = 1;i <= pos; i++) {
		if(a[i].people > peo) num++;
		else break;
	}
	
	if(num <= 3) ans2 = 1;
	if(ans1 >= 0.8 || ans2) puts("Yes");
	else puts("No");
}
/*
9 100
100 99 79 0 0 0 0 0 79
*/