#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int id;
	string s;
	string m;
	string x;
	string h;
} p[1000006];

bool cmp(node a, node b) {
	if(a.s.length() == b.s.length()) {
		if(a.s == b.s) {
			return a.id < b.id;
		}
		return a.s < b.s;
	}
	return a.s.length() < b.s.length();
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		p[i].id = i;
		cin >> p[i].s >> p[i].m >> p[i].x >> p[i].h;
	}
	sort(p+1, p+1+n, cmp);
	
	for(int i = 1;i <= n; i++) {
		cout << p[i].s <<  " " <<p[i].m << " " << p[i].x << " " << p[i].h << "\n";
	}
}