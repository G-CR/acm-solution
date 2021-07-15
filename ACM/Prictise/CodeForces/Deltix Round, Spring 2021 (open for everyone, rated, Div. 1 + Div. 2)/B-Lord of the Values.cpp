#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1003;

ll a[N];

int main() {
	int _; scanf("%d", &_); while(_--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		bool ok = 0;
		printf("%d\n", n*3);
		for(int i = 1; i <= n; i += 2) {
			int num = 6;
			while(num--) {
				printf("%d %d %d\n", ok==0?1:2, i, i+1);
				ok = !ok;
			}
		}
	}
}