#include <bits/stdc++.h>
using namespace std;

int n, q, head, tail;
int a[200005],ansa[200005], ansb[200005];
long long m[300005];

int main() {
	scanf("%d %d", &n, &q);
	head = 1, tail = n;
	int Max = -1, i;
	for(i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		Max = max(Max, a[i]);
	}
	for(i = 1;i <= q; i++) {
		scanf("%lld", &m[i]);
	}
	int cnt = 1;
	for(i = 1;i <= n; i++) {
		if(a[head] == Max) break;
		int A = a[head], B = a[head+1];
		ansa[i] = A, ansb[i] = B;
		if(i == m[cnt]) {
			printf("%d %d\n", A, B);
			cnt++;
		}
		if(A > B) {
			a[++tail] = B;
			a[++head] = A;
		} else {
			a[++tail] = A;
			head++;
		}
	}
	
	for(int j = cnt;j <= q; j++) {
		long long t = m[j]-i+1;
		if(m[j] < i) {
			printf("%d %d\n", ansa[m[j]], ansb[m[j]]);
			continue;
		}
		if(t > n-1) {
			t %= (n-1);
			if(t == 0) t = n-1;
		}
		printf("%d ", Max);
		printf("%d\n", a[head+t]);
	}
}