#include <bits/stdc++.h>
using namespace std;

int _, n;
string a;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		cin >> a;
		int pre = 1;
		for(int i = 0;i < a.length(); i++) {
			int t = a[i]-'0';
			if(i == 0) {
				printf("1");
				pre = 1 + t;
			}
			else {
				if(t + 1 == pre) {
					printf("0");
					pre = t;
				}
				else {
					printf("1");
					pre = t+1;
				}
			}
		}
		
		puts("");
	}
}