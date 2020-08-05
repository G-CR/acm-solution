#include <bits/stdc++.h>
using namespace std;

int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		int a, b, l;
		scanf("%d %d", &a, &b);
		if(b > a) swap(a, b);
		if(2*b >= a) {
			l = b;
			l *= 2;
		}
		else l = a;
		printf("%d\n", l*l);
	}
}