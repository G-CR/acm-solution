#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
vector <long long> res, t;
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	res.push_back(a[1]);
	
	long long lar = (long long)2<<30;
	for(long long k = 1;k <= lar; k <<= 1) {
		for(int i = 1;i <= n; i++) {
			t.clear();
			bool left = binary_search(a+1, a+1+n, a[i]-k);
			bool right = binary_search(a+1, a+1+n, a[i]+k);

			t.push_back(a[i]);
			if(left && right) {
				t.push_back(a[i]-k);
				t.push_back(a[i]+k);
			} 
			else if(left) t.push_back(a[i]-k);
			else if(right) t.push_back(a[i]+k);
			
			if(t.size() > res.size()) {
				res.clear();
				for(int j = 0;j < t.size(); j++) res.push_back(t[j]);
			}
		}
	}
	printf("%d\n",(int)res.size());
	for(int i = 0;i < res.size(); i++) printf("%lld ", res[i]);
}