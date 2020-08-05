#include <bits/stdc++.h>
using namespace std;

int _;
int a, b;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &a, &b);
		if(a <= b) printf("%d\n", b-a);
		else {
			int t = a % b;
			printf("%d\n",t == 0?0:b-t);
		}
	}
}