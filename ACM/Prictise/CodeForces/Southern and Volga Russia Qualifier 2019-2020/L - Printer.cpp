#include <bits/stdc++.h>
using namespace std;

int n, k, Max1, Max2, ans1, ans2;
char s1[1005], s2[1005];


int main() {
	scanf("%d %d", &n, &k);
	scanf("%s %s", s2+1, s1+1);
	
	int t = 0, Max = -1, ans = 10000000;
	for(int cnt = 1;cnt <= n; cnt++) { //1f
		Max = -1;
		for(int i = 1;i <= n; i++) {
			if(s1[i] == '1') {
				t = abs(i - cnt);
				if(Max < t) {
					Max = t;
					Max1 = 1; Max2 = cnt;
				}
			}
			
			if(s2[i] == '1') {
				t = (i + k + cnt);
				if(Max < t) {
					Max = t;
					Max1= 1; Max2 = cnt;
				}
			} 
			
		}
		
		if(ans > Max) {
			ans = Max;
			ans1 = Max1; ans2 = Max2;
		}
	}
	
	
	for(int cnt = 1;cnt <= n; cnt++) { //2f
		Max = -1;
		for(int i = 1;i <= n; i++) {
			if(s2[i] == '1') {
				t = abs(i - cnt);
				if(Max < t) {
					Max = t;
					Max1= 2; Max2 = cnt;
				}
			} 
			
			if(s1[i] == '1') {
				t = (i + k + cnt);
				if(Max < t) {
					Max = t;
					Max1 = 2; Max2 = cnt;
				}
			} 
		}
		
		if(ans > Max) {
			ans = Max;
			ans1 = Max1; ans2 = Max2;
		}
	}
	printf("%d\n%d %d\n", ans, ans1, ans2);
}