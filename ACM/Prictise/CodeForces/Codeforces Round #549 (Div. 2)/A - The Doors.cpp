#include <bits/stdc++.h>
using namespace std;

int Left, Right, n;
int a[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] == 0) Left++;
		else Right++;
	}
	
	int cnt = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] == 0) Left--;
		else Right--;
		cnt++;
		if(!Left || !Right) break;
	}
	printf("%d\n", cnt);
}