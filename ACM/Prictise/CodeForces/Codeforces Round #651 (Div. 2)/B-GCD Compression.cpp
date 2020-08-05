#include <bits/stdc++.h>
using namespace std;

int _, n;
struct node {
	int dig, pos;
}a[2002];
queue <int> ji, ou;

int main() {
	scanf("%d", &_);
	while(_--) {
		while(!ji.empty()) ji.pop();
		while(!ou.empty()) ou.pop();
		scanf("%d", &n);
		for(int i = 1;i <= 2*n; i++) {
			scanf("%d", &a[i].dig);
			a[i].pos = i;
			if(a[i].dig%2 == 0) ou.push(a[i].pos);
			else ji.push(a[i].pos);
		}
		
		int num = n-1;
		while(num--) {
			if(ou.size() >= 2) {
				int f = ou.front(); ou.pop();
				int s = ou.front(); ou.pop();
				printf("%d %d\n", f, s);
			}
			else {
				int f = ji.front(); ji.pop();
				int s = ji.front(); ji.pop();
				printf("%d %d\n", f, s);
			}
		}
	}
}