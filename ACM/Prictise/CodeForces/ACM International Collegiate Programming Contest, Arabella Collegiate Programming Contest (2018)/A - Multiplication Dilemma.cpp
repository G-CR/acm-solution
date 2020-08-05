#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll a,b;
ll ans1[20], ans2[20];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &a, &b);
		ll t1 = a, t2 = b, ia = 10, ja = 1, ib = 10, jb = 1;
		
		int cnt1 = 0;
		if(abs(t1) == 1) ans1[++cnt1] = t1;
		while(ja < abs(t1)) {
			if(t1 % ia) {
				if(abs(t1*ja) < ia) ans1[++cnt1] = t1;
				else ans1[++cnt1] = t1/ja*ja%ia;
			}
			else if(abs(t1) == ia) ans1[++cnt1] = t1;
			ia *= 10; ja *= 10;
		}
//		for(int i = 1;i <= cnt1; i++) printf("%lld ", ans1[i]); puts("");
		
		int cnt2 = 0;
		if(abs(t2) == 1) ans2[++cnt2] = t2;
		while(jb < abs(t2)) {
			if(t2 % ib) {
				if(abs(t2*jb) < ib) ans2[++cnt2] = t2;
				else ans2[++cnt2] = t2/jb*jb%ib;
			}
			else if(abs(t2) == ib) ans2[++cnt2] = t2;
			ib *= 10; jb *= 10;
		}
//		for(int i = 1;i <= cnt2; i++) printf("%lld ", ans2[i]); puts("");
		
		bool ok = 0;
		for(int i = 1;i <= cnt1; i++) {
			for(int j = 1;j <= cnt2; j++) {
				if(ans1[i]*ans2[j] > 0) {
					if(!ok) {
						ok = 1;
						printf("%lld x %lld ", abs(ans1[i]), abs(ans2[j]));
					}
					else {
						printf("+ %lld x %lld ", abs(ans1[i]), abs(ans2[j]));
					}
				}
				else {
					if(!ok) {
						ok = 1;
						printf("-%lld x %lld ", abs(ans1[i]), abs(ans2[j]));
					}
					else {
						printf("- %lld x %lld ", abs(ans1[i]), abs(ans2[j]));
					}
				}
			}
		}
		puts("");
	}
}