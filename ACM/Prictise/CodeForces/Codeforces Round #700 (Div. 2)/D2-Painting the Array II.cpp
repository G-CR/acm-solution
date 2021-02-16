#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005], pos[100005], nxt[100005];
vector <int> v1, v2, d[100005];

int cal() {
	int ans = 0, pre = -1;
	for(int i = 1;i < v1.size(); i++) {
		if(v1[i] != pre) {
			pre = v1[i];
			ans++;
		}
	}
	pre = -1;
	for(int i = 1;i < v2.size(); i++) {
		if(v2[i] != pre){
			pre = v2[i];
			ans++;
		}
	}
	return ans;
}

int getp(int now, int pos) {
	vector <int> t = d[now];
	int l = 0, r = t.size()-1, ans = n+1;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(t[mid] >= pos) {
			ans = t[mid];
			r = mid-1;
		}
		else l = mid+1;
	}
	
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		d[a[i]].push_back(i);
	}
	
	v1.push_back(-1);
	v2.push_back(-1);
	
	for(int i = 1; i <= n; i++) {
		if(v1[v1.size()-1] == v2[v2.size()-1])
			v1.push_back(a[i]);
		else if(v1[v1.size()-1] != a[i] && v2[v2.size()-1] == a[i]) v2.push_back(a[i]);
		
		else if(v1[v1.size()-1] == a[i] && v2[v2.size()-1] != a[i]) v1.push_back(a[i]);
		
		else if(getp(v1[v1.size()-1], i) <= getp(v2[v2.size()-1], i)) v2.push_back(a[i]);
		else
			v1.push_back(a[i]);
	}
	
	printf("%d\n", cal());
}