#include <bits/stdc++.h>
using namespace std;

int n, m;
struct node {
	int dig, id;
} a1[100005], a2[100005];
int b[100005], c[100005];

bool cmp1 (node a, node b) {
	if(a.dig == b.dig) return a.id < b.id;
	return a.dig < b.dig;
}
bool cmp2 (node a, node b) {
	if(a.dig == b.dig) return a.id > b.id;
	return a.dig > b.dig;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a1[i].dig);
		a1[i].id = i;
		a2[i].dig = a1[i].dig;
		a2[i].id = a1[i].id;
	}
	sort(a1+1, a1+1+n, cmp1);
	sort(a2+1, a2+1+n, cmp2);
	for(int i = 1;i <= n; i++) b[i] = a1[i].dig, c[i] = a2[i].dig;
	
	int ans = 2e6, ansi = 2e5;
	for(int i = 1;i <= n; i++) {
		int p1 = lower_bound(b+1, b+1+n, -b[i])-b;
		int p2 = lower_bound(c+1, c+1+n, -b[i], greater<int>())-c;
		if(a1[p1].id == a1[i].id) p1++;
		if(a2[p2].id == a1[i].id) p2++;
//		cout << p1 << " " << p2 << endl;
		if(p1 != n+1) {
			if(ans > abs(b[i]+b[p1])) {
				ans = abs(b[i]+b[p1]);
				ansi = a1[p1].id + a1[i].id;
			}
			else if(ans == abs(b[i]+b[p1])) ansi = min(ansi, a1[p1].id+a1[i].id);
			
		}
		if(p2 != n+1) {
			if(ans > abs(b[i]+c[p2])) {
				ans = abs(b[i]+c[p2]);
				ansi = a2[p2].id + a1[i].id;
			}
			else if(ans == abs(b[i]+c[p2])) ansi = min(ansi, a2[p2].id+a1[i].id);

		}
	}
	printf("%d %d\n", ans, ansi);
}