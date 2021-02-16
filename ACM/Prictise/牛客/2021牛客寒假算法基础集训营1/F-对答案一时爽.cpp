#include <bits/stdc++.h>
using namespace std;

int n;
char a[103], b[103];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf(" %c", &a[i]);
	for(int i = 1;i <= n; i++) scanf(" %c", &b[i]);
	
	int ansma = 0, ansmi = 0;
	for(int i = 1;i <= n; i++) {
		int ma = -1, mi = 100, now;
		for(char j = 'A'; j <= 'D'; j++) {
			if(a[i] == j && b[i] == j) now = 2;
			else if(a[i] == j || b[i] == j) now = 1;
			else now = 0;
			ma = max(ma, now);
			mi = min(mi, now);
		}
		ansma += ma;
		ansmi += mi;
	}
	
	printf("%d %d\n", ansma, ansmi);
}