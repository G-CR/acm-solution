#include <bits/stdc++.h>
using namespace std;

long long t1, t2;

int main() {
	long long ans = 0;
	while(~scanf("%lld %lld", &t1, &t2)) {
		ans = 0;
		int now = t1 % 60;
		if(now == 0) t1++;
		else if(now >= 51 && now <= 59) t1 += (61-now);
		else {
			ans += (51-now);
			t1 += (61-now);
		}
		ans += ((t2-t1+1)/60*50);
		ans += min((t2-t1+1)%60, (long long)50);
		printf("%lld\n", ans);
	}
}