#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int num[30];

bool check() {
	for(int i = 0;i <= 20; i++) if(num[i]) return 0;
	return 1;
}

int qpow(int x, int n) { 
	int res = 1; 
	for (; n; n >>= 1, x = x * x) 
		if (n & 1) res = res * x; 
	return res; 
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		int t = a[i], cnt = 0;
		while(t) {
			if(t&1) num[cnt]++;
			t >>= 1;
			cnt++;
		}
	}
//	for(int i = 0;i <= 20; i++) cout << num[i] << " ";
	
	vector<long long> v;
	
	while(!check()) {
		long long t = 0;
		for(int i = 20;i >= 0; i--) {
			if(num[i]) {
				t += qpow(2, i);
				num[i]--;
			}
		}
		v.push_back(t);
	}
	
	long long sum = 0;
	for(int i = 0;i < v.size(); i++) {
		sum += v[i]*v[i];
	}
	
	printf("%lld\n", sum);
}