#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
	scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
	sort(a+1, a+5);
	if(a[1]+a[4] == a[2]+a[3] || a[4] == a[1]+a[2]+a[3]) puts("YES");
	else puts("NO");
}