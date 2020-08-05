#include <bits/stdc++.h>
using namespace std;

int n;
int a[15000];

int main() {
	scanf("%d", &n);
	int num = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	bool ok1 = 0, ok2 = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] % 2 == 0) printf("%d\n", a[i]/2);
		else {
			if(a[i] < 0) {
				if(!ok1) printf("%d\n", a[i]/2), ok1 = 1;
				else printf("%d\n", (a[i]-1)/2), ok1 = 0;
			}
			
			if(a[i] > 0) {
				if(!ok2) printf("%d\n", a[i]/2), ok2 = 1;
				else printf("%d\n", (a[i]+1)/2), ok2 = 0;
			}
		}
	}
}