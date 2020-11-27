#include <bits/stdc++.h>
using namespace std;

int n, op, x;
int a = 0, b = (1<<20)-1;
int Xor = 0, And = (1<<20)-1, Or = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &op, &x);
		if(op == 1) a &= x, b &= x;
		if(op == 2) a |= x, b |= x;
		if(op == 3) a ^= x, b ^= x;
	}
	
	for(int i = 0;i < 20; i++) {
		int t1 = (a >> i) & 1, t2 = (b >> i) & 1;
		if(!t1 && !t2) And -= (1 << i);
		if(t1 && t2) Or += (1 << i);
		if(t1 && !t2) Xor += (1 << i);
	}
	
	puts("3");
	printf("1 %d\n", And);
	printf("2 %d\n", Or);
	printf("3 %d\n", Xor);
}