#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main() {
	scanf("%d", &n);
	bool ok = 1;
	if(n % 2 != 0) ok = 0;
	int Min = 1000006, Mini;
	
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(Min > a[i]) {
			Min = a[i];
			Mini = i;
		}
	}
	
	for(int i = 1;i <= n; i++) {
		if(a[i] >= 0) {
			a[i] = -1*a[i]-1;
			if(Min > a[i]) {
				Min = a[i];
				Mini = i;
			}
		}
	}
	
	if(!ok) {
		a[Mini] = -1*a[Mini]-1;
	}
	
	for(int i = 1;i <= n; i++) printf("%d ", a[i]);
	puts("");
}