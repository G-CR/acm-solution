#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
	scanf("%d", &n);
	string t = "x^";
	bool kt = 0;
	
	for(int i = 1;i <= n+1; i++) {
		scanf("%d", &x);
		if(x == 0) continue;
		
		if(i == n+1 && kt) {
			if(x > 0) printf("+%d", x);
			if(x < 0) printf("%d", x);
			continue;
		}
		if(!kt) {
			kt = 1;
			if(x > 0) {if(x != 1) printf("%d", x);} 
			else {
				if(x == -1) printf("-");
				else printf("%d", x);
			} 
		}
		else {
			if(x > 0) {
				if(x == 1) printf("+");
				else printf("+%d", x);
			}
			if(x < 0) {
				if(x == -1) printf("-");
				else printf("%d", x);			
			}
		}
		if(i == n) cout << "x";
		else cout << t << n-i+1;
	}
}