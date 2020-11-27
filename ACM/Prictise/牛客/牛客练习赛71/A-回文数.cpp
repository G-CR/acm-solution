#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
	for(int i = 0;i < 10; i++) scanf("%d", &a[i]);
	bool ok = 1;
	
	int numj = 0;
	for(int i = 0;i < 10; i++) {
		if(a[i]%2) numj++;
	} 
	if(numj > 1) return puts("-1"), 0;
	
	int numfl = 0, ma = 0;
	for(int i = 1;i < 10; i++) {
		if(a[i]) numfl++;
		ma = max(ma, a[i]);
	}
	if(a[0] && numfl == 1 && ma == 1) return puts("-1"), 0;
	
	int pos = -1;
	for(int i = 0;i < 10; i++) {
		if(a[i]%2) pos = i;
	}
	
	vector <int> ans;
	
	for(int i = 0;i < 10; i++) a[i] /= 2;
	for(int i = 1;i < 10; i++) {
		if(a[i]) {
			ans.push_back(i);
			a[i]--;
			break;
		}
	}
	while(a[0]--) ans.push_back(0);
	for(int i = 1;i < 10; i++) while(a[i]--) ans.push_back(i);
	
	for(int i = 0;i < ans.size(); i++) printf("%d", ans[i]);
	if(pos != -1) printf("%d", pos);
	for(int i = ans.size()-1; i >= 0; i--) printf("%d", ans[i]);
	puts("");
}