#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;


char a[105], b[105];
int n1,n2,t1,t2,ok;

int zhengshu() {
	for(int i = 1;i <= min(n1,n2);i++) {
		if(a[i] == '.') t1 = i;
		if(b[i] == '.') t2 = i;
	}
	
	if(t1 > t2) return 1;
	else if(t1 < t2) return -1;
	else {
		for(int i = 1;i <= t1; i++) {
			if(a[i] > b[i]) return 1;
			else if(a[i] < b[i]) return -1;
		}
	}
	return 0;
}

int xiaoshu() {
	if(n1 > n2) for(int i = n2+1;i <= n1; i++) b[i] = '0';
	else if(n1 < n2) for(int i = n1+1;i <= n2; i++) a[i] = '0';
	for(int i = t1+1;i <= max(n1,n2); i++) {
		if(a[i] > b[i]) return 1;
		else if(a[i] < b[i]) return -1;
	}
	return 0;
}

int main() {
	int p = 1;
	while(~scanf("%s %s", a+1, b+1)) {
		printf("Case %d: ", p++);
		n1 = strlen(a+1); n2 = strlen(b+1);
		
		int ans = zhengshu();
		if(ans == 1) puts("Bigger");
		else if(ans == -1) puts("Smaller");
		else {
			ans = xiaoshu();
			if(ans == 1) puts("Bigger");
			else if(ans == -1) puts("Smaller");
			else puts("Same");
		}
	}
}