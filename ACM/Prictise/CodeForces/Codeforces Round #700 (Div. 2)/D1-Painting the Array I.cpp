#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
vector <int> v1, v2;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	v1.push_back(-1); v2.push_back(-1);
	for(int i = 1;i <= n; i++) {
		if(i+1 <= n && a[i+1] == v2[v2.size()-1]) v2.push_back(a[i]);
		else if(v1[v1.size()-1] != a[i]) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	
	int ans = 0, pre = -1;
	for(int i = 1;i < v1.size(); i++) {
		if(v1[i] != pre){
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
	
	printf("%d\n", ans);
}

