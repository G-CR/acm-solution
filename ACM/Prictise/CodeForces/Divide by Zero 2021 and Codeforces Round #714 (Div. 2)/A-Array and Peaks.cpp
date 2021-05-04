#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[103];

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++) a[i] = i;
		int pos = 2;
		while(pos+1 <= n && k--) {
			swap(a[pos], a[pos+1]);
			pos += 2;
		}
		if(k > 0) puts("-1");
		else {
			for(int i = 1; i <= n; i++) {
				printf("%d ", a[i]);
			} puts("");
		}
	}
}