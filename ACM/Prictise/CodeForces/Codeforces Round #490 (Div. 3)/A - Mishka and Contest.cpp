#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[105];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int head = 1, tail = n;
	int sum = 0;
	while(head <= tail) {
		if(a[head] <= k) {
			sum++;
			head++;
		}
		else if(a[tail] <= k) {
			sum++;
			tail--;
		}
		else break;
	}
	printf("%d\n", sum);
}