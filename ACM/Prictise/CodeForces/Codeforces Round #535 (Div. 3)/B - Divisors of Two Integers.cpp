#include<bits/stdc++.h>
using namespace std;

int n,a[200],b[200],num[10004],ans1,ans2;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1,a+1+n);
	ans1 = a[n];
	int j = 0;
	for(int i = n;i >= 1; i--) {
		if(ans1 % a[i] == 0 && num[a[i]] == 0) {
			num[a[i]]++;
		} else {
			b[++j] = a[i];
		}
	}
	sort(b+1,b+1+j);
	ans2 = b[j];
	printf("%d %d\n", ans1, ans2);
}