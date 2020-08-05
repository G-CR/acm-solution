#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000006];
vector <long long> vc[5];

long long cal(int pos, int end) {
	long long tot = 0;
	for(int i = 0;i < end; i++) {
		tot += vc[pos][i];
	}
	return tot;
}

bool check(int pos, int num) {
	if(vc[pos].size() >= num) return 1;
	return 0;
}

int main() {
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	for(int i = 1;i <= n; i++) {
		vc[a[i]%5].push_back(a[i]);
	}
	for(int i = 1;i <= 4; i++) {
		sort(vc[i].begin(), vc[i].end());
	}
	
//	for(int i = 0;i <= 4; i++) {
//		for(int j = 0;j < vc[i].size(); j++) cout << vc[i][j] << " "; puts("");
//	}
	int mod = sum % 5;
	long long ans = 1e18, t = 1e18;
	if(mod == 1) {
		if(check(1,1)) t = min(t, cal(1, 1)); // 1
		if(check(2,3)) t = min(t, cal(2, 3)); // 6
		if(check(3,2)) t = min(t, cal(3, 2)); // 6
		if(check(3,2)) t = min(t, cal(3, 2)); // 6
		if(check(2,1) && check(4,1)) t = min(t, cal(2,1)+cal(4,1)); // 6
		if(check(3,1) && check(4,2)) t = min(t, cal(3,1)+cal(4,2)); // 11
		if(check(4,4)) t = min(t, cal(4, 4)); // 16
	}
	else if(mod == 2) {
		if(check(1,2)) t = min(t, cal(1,2)); // 2
		if(check(2,1)) t = min(t, cal(2,1)); // 2
		if(check(3,1) && check(4,1)) t = min(t, cal(3,1)+cal(4,1)); // 7
		if(check(1,1) && check(3,2)) t = min(t, cal(1,1)+cal(3,2)); // 7
		if(check(3,4)) t = min(t, cal(3,4)); // 12
		if(check(4,3)) t = min(t, cal(4,3)); // 12
		if(check(4,2) && check(3,3)) t = min(t, cal(4,2)+cal(3,3)); // 17
	}
	else if(mod == 3) {
		if(check(3,1)) t = min(t, cal(3,1)); // 3
		if(check(1,3)) t = min(t, cal(1,3)); // 3
		if(check(1,1) && check(2,1)) t = min(t, cal(1,1)+cal(2,1)); // 3
		if(check(4,2)) t = min(t, cal(4,2)); // 8
		if(check(2,4)) t = min(t, cal(2,4)); // 8
		if(check(2,2) && check(4,1)) t = min(t, cal(2,2)+cal(4,1)); // 8
	}
	else if(mod == 4) {
		if(check(4,1)) t = min(t, cal(4,1)); // 4
		if(check(1,4)) t = min(t, cal(1,4)); // 4
		if(check(2,2)) t = min(t, cal(2,2)); // 4
		if(check(1,1) && check(3,1)) t = min(t, cal(1,1)+cal(3,1)); // 4
		if(check(1,2) && check(2,1)) t = min(t, cal(1,2)+cal(2,1)); // 4
		if(check(1,9)) t = min(t, cal(1,9)); // 9
		if(check(3,3)) t = min(t, cal(3,3)); // 9
	}
	if(t == 1e18) t = 0;
	printf("%lld\n", sum-t);
}

// check(,)