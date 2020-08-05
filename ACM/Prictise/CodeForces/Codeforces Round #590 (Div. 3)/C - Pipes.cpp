#include <bits/stdc++.h>
using namespace std;

int q,n;
char s1[200005],s2[200005];
int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		scanf("%s %s", s1+1, s2+1);
		int end = 1;
		bool ok = 1;
		for(int i = 1;i <= n; i++) {
			if(end == 1) {
				if(s1[i] <= '2') {
					end = 1;
				}
				else if(s1[i] >= '3' && s2[i] >= '3') {
					end = 2;
				}
				else {
					ok = 0;
					break;
				}
			}
			
			else if(end == 2){
				if(s2[i] <= '2') {
					end = 2;
				}
				else if(s2[i] >= '3' && s1[i] >= '3') {
					end = 1;
				}
				else {
					ok = 0;
					break;
				}
			}
		}
		if(end == 2 && ok) puts("YES");
		else puts("NO");
	}
}