#include <bits/stdc++.h>
using namespace std;

int n, a;

int main() {
	scanf("%d", &n);
	int num25 = 0, num50 = 0, num100 = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a);
		if(a == 25) num25++;
		else if(a == 50) num50++;
		else if(a == 100) num100++;
	}
	
	bool ok = 1;
	
	if(num50 > num25) {
		ok = 0;
	}
	else {
		num25 -= num50;
	}
	
	int mi = min(num25, num50);
	num100 -= mi;
	num25 -= mi; num50 -= mi;
	if(num100 > 0) {
		num100 -= num25/3;
	}
	
	if(num100 > 0) {
		ok = 0;
	}
	
	if(ok) puts("YES");
	else puts("NO");
}