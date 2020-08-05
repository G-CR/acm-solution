#include<bits/stdc++.h>
using namespace std;
 
int n, a[4005];
char s[] = "occsu";
 
void isprime() {
	a[2] = 1;
	for(int i = 3;i <= 4000; i++) {
		for(int j = 2;j <= sqrt(i)+1; j++) {
			if(i % j == 0) {
				a[i] = 0;
				break;
			}
			a[i] = 1;
		}
	}
}
 
int main() {
	isprime();
	scanf("%d", &n);
	for(int i = 1;i <= 4*n; i++) {
		int t = i%4; if(t == 0) t = 4;
		if(a[i]) printf("%c", s[t]-32);
		else printf("%c", s[t]);
	}
}