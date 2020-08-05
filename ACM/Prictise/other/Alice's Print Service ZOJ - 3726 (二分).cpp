#include <iostream>
using namespace std;

int _, n, m;
long long s[100005], p[100005], now[100005], q;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &s[i], &p[i]);
		}
		
		long long minn = 1e18;
		for(int i = n;i >= 1; i--) {
			minn = min(minn, s[i]*p[i]);
			now[i] = minn;
//			cout <<"! "<< now[i] << endl;
		}
		
		while(m--) {
			scanf("%lld", &q);
			if(q >= s[n]) printf("%lld\n", q*p[n]);
			else {
				int cnt = lower_bound(s+1, s+1+n, q) - s;
//				cout << "cnt = " << cnt << endl;
				
				printf("%lld\n", min(now[cnt], q*p[cnt-1]));
			}
			
		}
	}
}