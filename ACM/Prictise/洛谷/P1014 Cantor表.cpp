#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int i = 0, j = 0;
	while(j < n) {
		i++;
		j += i;
	}
	if(i % 2 == 0) printf("%d/%d\n", i-(j-n), j-n+1);
	else printf("%d/%d\n", j-n+1, i-(j-n));
}