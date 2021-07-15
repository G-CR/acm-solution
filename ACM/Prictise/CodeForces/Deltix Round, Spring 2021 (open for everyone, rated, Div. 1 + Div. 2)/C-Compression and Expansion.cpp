#include <bits/stdc++.h>
using namespace std;

int a[1003];
vector <int> v;

int main() {
	int _; scanf("%d", &_); while(_--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		v.clear();
		for(int i = 1; i <= n; i++) {
			if(a[i] == 1) v.push_back(1);
			else {
				while(!v.empty() && v.back()+1 != a[i]) {
					v.pop_back();
				}
				v.back() = a[i];
			}
			
			printf("%d", v[0]);
			for(int i = 1; i < v.size(); i++) {
				printf(".%d", v[i]);
			} puts("");
		}
	}
}