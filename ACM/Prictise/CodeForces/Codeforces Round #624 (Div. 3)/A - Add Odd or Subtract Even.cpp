#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		if(a == b) puts("0");
		else if(a < b) {
			if((b-a)%2) puts("1");
			else puts("2");
		}
		else if(a > b) {
			if((a-b)%2) puts("2");
			else puts("1");
		}
	}
}