#include <bits/stdc++.h>
using namespace std;

int t,a,b,c,n;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &a, &b ,&n);
		printf("%d\n",(n%3==0)?a:(n%3==1)?b:a^b);
	}
}