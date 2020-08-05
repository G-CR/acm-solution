#include <bits/stdc++.h>
using namespace std;

int n, a[200005], num[200005];
vector <pair<int, int> > vc;
vector <int> ad;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		num[a[i]]++;
	}
	
	int pos = 1, Max = 1, now = a[1];
	for(int i = 1;i <= n; i++) {
		if(num[a[i]] > Max) {
			Max = num[a[i]];
			pos = i;
			now = a[i];
		}
	}
	
	for(int i = pos-1;i >= 1; i--) {
		if(a[i] != now) {
			if(a[i] > now) ad.push_back(2);
			else ad.push_back(1);
			a[i] = now;
			vc.push_back(make_pair(i, i+1));
		}
	}
	
	for(int i = pos+1;i <= n; i++) {
		if(a[i] != now) {
			if(a[i] > now) ad.push_back(2);
			else ad.push_back(1);
			a[i] = now;
			vc.push_back(make_pair(i, i-1));
		}
	}
	
	int cnt = vc.size();
	printf("%d\n", cnt);
	for(int i = 0;i < cnt; i++) {
		printf("%d %d %d\n", ad[i], vc[i].first, vc[i].second);
	}
}