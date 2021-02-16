#include <bits/stdc++.h>
using namespace std;

int n;
char x;
int num[4];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf(" %c", &x);
		if(x == 'k') num[0]++;
		else if(x == 'i') num[1]++;
		else if(x == 'n') num[2]++;
		else if(x == 'g') num[3]++;
	}
	
	int mi = min(min(num[1], num[2]), num[3]);
	int res = min(num[0], mi/2);
	num[0] -= res; mi -= res*2;
	res *= 2;
	if(num[0] && mi) res++;
	
	printf("%d\n", res);
}