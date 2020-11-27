#include <bits/stdc++.h>
using namespace std;

string s;
int numb, nums, numc;
int pb, ps, pc;
int needb, needs, needc;
long long mon;

bool check(long long k) {
	long long sheng = mon;
	long long xub = max(k*needb - numb, 1LL*0);
	long long xus = max(k*needs - nums, 1LL*0);
	long long xuc = max(k*needc - numc, 1LL*0);
	sheng -= (xub*pb + xus*ps + xuc*pc);
	return sheng >= 0;
}

int main() {
	while(cin >> s) {
		scanf("%d %d %d", &numb, &nums, &numc);
		scanf("%d %d %d", &pb, &ps, &pc);
		scanf("%lld", &mon);
		for(char i: s) {
			if(i == 'B') needb++;
			if(i == 'S') needs++;
			if(i == 'C') needc++;
		}
		long long l = 0, r = 1e13, ans;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if(check(mid)) {
				ans = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		
		printf("%lld\n", ans);
	}
}