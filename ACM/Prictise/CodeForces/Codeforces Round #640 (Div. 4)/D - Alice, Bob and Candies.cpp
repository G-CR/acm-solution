#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[1005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int l = 1, r = n, Alice = 0, Bob = 0, t1 = 0, t2 = 0, ans = 0;
		while(l <= r) {
			t1 = 0;
			while(l <= r && t1 <= t2) {
				t1 += a[l++];
			}
			if(t1) ans++;
			Alice += t1;
//			cout << "t1 = " << t1 << endl;
			t2 = 0;
			while(l <= r && t2 <= t1) {
				t2 += a[r--];
			}
			if(t2) ans++;
//			cout << "t2 = " << t2 << endl << endl;
			Bob += t2;
		}
		cout << ans << " " << Alice << " " << Bob << endl;
	}
}