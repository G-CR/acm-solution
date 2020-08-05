#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
vector <pair<long long, long long> > vc;
int _;
long long n;

int main() {
	vc.push_back(make_pair(1, 1));
	vc.push_back(make_pair(2, 3));
	long long tail = 3;
	while(tail < N) {
//		printf("%lld %lld\n", tail+1, tail%2?2*tail:2*tail+1);
		vc.push_back(make_pair(tail+1, tail%2?2*tail:2*tail+1));
		tail = tail%2?2*tail:2*tail+1;
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		for(int i = 0;i < vc.size(); i++) {
			if(n >= vc[i].first && n <= vc[i].second) {
				if(i%2==0) puts("XiaoQiao");
				else puts("XiaoHuiHui");
				break;
			}
		}
	}
}