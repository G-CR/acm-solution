#include <bits/stdc++.h>
using namespace std;

int dir;
long long x, y;

void walk(int wh, int k, long long &x, long long &y) {
	if(dir == 0) {
		if(wh == 0) y+=k;
		else if(wh == 1) x-=k;
		else if(wh == 2) y-=k;
		else x+=k;
	}
	else if(dir == 1) {
		if(wh == 0) x-=k;
		else if(wh == 1) y-=k;
		else if(wh == 2) x+=k;
		else y+=k;
	}
	else if(dir == 2) {
		if(wh == 0) y-=k;
		else if(wh == 1) x+=k;
		else if(wh == 2) y+=k;
		else x-=k;
	}
	else {
		if(wh == 0) x+=k;
		else if(wh == 1) y+=k;
		else if(wh == 2) x-=k;
		else y-=k;
	}
}

int main() {
	int _; cin >> _; while(_--) {
		int n; cin >> n;
		dir = 0; x = 0, y = 0;
		for(int i = 1; i <= n; i++) {
			char op; long long k; cin >> op >> k;
			if(op == 'r') {
				dir += k; dir %= 4;
			}
			else if(op == 'l') {
				dir -= k; dir += 400000; dir %= 4;
			}
			else {
				if(op == 'w') {
					walk(0, k, x, y);
				}
				else if(op == 'a') {
					walk(1, k, x, y);
				}
				else if(op == 's') {
					walk(2, k, x, y);
				}
				else {
					walk(3, k, x, y);
				}
			}
			
//			printf("%d %d\n", x, y);
		}
//		puts("");
		printf("%lld %lld\n", x, y);
	}
}