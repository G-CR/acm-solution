#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int n, m;
int a[N];
map <int, int> num;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		num[a[i]]++;
	}
	
	sort(a+1, a+1+n);
	for(int i = 1;i <= n; i++) {
		if(a[i] >= m) break;
		num[a[i]]--;
		if(num[m-a[i]]) {
			printf("%d %d\n", a[i], m-a[i]);
			return 0;
		}
		else num[a[i]]++;
	}
	
	puts("No Solution");
}