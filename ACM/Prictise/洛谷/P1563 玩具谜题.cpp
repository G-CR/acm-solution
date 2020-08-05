#include <bits/stdc++.h>
using namespace std;

struct people {
	int pos;
	string name;
} peo[100005];
int n, m, a, step;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &peo[i].pos);
		cin >> peo[i].name;
	}
	
	int now = 1;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &a, &step);
		if(peo[now].pos == 1) {
			if(a == 1) {
				if(now - step >= 1) {
					now -= step;
				}
				else {
					step -= now;
					now = n - step;
				}
			}
			if(a == 0) {
				if(now + step <= n) {
					now += step;
				}
				else {
					step -= (n-now);
					now = step;
				}
			}
		}
		else if(peo[now].pos == 0) {
			if(a == 1) {
				if(now + step <= n) {
					now += step;
				}
				else {
					step -= (n-now);
					now = step;
				}
			}
			if(a == 0) {
				if(now - step >= 1) {
					now -= step;
				}
				else {
					step -= now;
					now = n - step;
				}
			}
		}
	}
	cout << peo[now].name << endl;
}