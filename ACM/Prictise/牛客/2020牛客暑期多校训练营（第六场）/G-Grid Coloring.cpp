#include <bits/stdc++.h>
using namespace std;

int _, n, k;
vector <int> heng, shu;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		if(n==1||k==1||2*n*(n+1)%k) puts("-1");
		else {
			heng.clear(); shu.clear();
			int num = 1;
			for(int i = 1;i <= n; i++) {
				for(int j = 1;j <= n; j++) {
					if(num > k) num -= k;
					heng.push_back(num++);
				}
				for(int j = 1;j <= n+1; j++) {
					if(num > k) num -= k;
					shu.push_back(num++);
				}
			}
			for(int j = 1;j <= n; j++) {
				if(num > k) num -= k;
				heng.push_back(num++);
			}
			
			int j = 1;
			for(int i: heng) {
				printf("%d%c", i, j==n?'\n':' ');
				j++; if(j > n) j -= n;
			}
			
			for(int i = 0;i <= n; i++) {
				for(int j = i, cnt = 1; cnt <= n; j += (n+1), cnt++) {
					printf("%d%c", shu[j], cnt==n?'\n':' ');
				}
			}
		}
	}
}