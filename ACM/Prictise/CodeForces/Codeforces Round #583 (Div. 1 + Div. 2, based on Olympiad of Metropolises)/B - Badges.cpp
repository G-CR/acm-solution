#include <bits/stdc++.h>
using namespace std;
 
int b,g,n;
 
int main() {
	scanf("%d %d %d", &b, &g, &n);
	if(b < n && g < n) {
		int t = n-max(b,g);
		printf("%d\n",min(b,g)-t+1);
	}
	else if(b >= n || g >= n){
		printf("%d\n", min(b,min(g,n))+1);
	}
	else if(b+g > n) {
		printf("%d\n",(((b+g)-n)+1)*2);
	}
	else if(b+g == n) {
		puts("1");
	}
}