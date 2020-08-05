#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T,n,a,b;
string s;
ll cost1,cost2;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld %lld", &n, &a, &b);
		cin >> s;
		ll n = s.length();
		cost1 = 0; cost2 = b;
		ll end = 1;
		for(ll i = 0;i < n; i++) {
			if(i == n-1) {
				if(end == 1){
					cost1 += a; cost2 += b;
				}
				else if(end == 2) {
					cost1 += 2*a; cost2 += b;
				}
				continue;
			}
			
			if(s[i] == '1') {
				cost1 += a; cost2 += 2*b; end = 2;
			}
			
			if(s[i] == '0') {
				if(end == 1) {
					if(s[i+1] == '1') {
						cost1 += 2*a; cost2 += 2*b; end = 2;
					}
					else if(s[i+1] == '0') {
						cost1 += a; cost2 += b; end = 1;
					}
				}
				else if(end == 2) {
					if(s[i+1] == '1') {
						cost1 += a; cost2 += 2*b; end = 2;
					}
					else if(s[i+1] == '0'){
						ll j = 1;
						while(s[i+j] == '0' && i+j < n) j++; j--;
						if(i+j == n-1) {
							cost1 += 2*a+j*a; cost2 += (j+1)*b;
							break;
						}
						if((4*a+3*b) + (j-1)*(a+b) < (j+1)*(a+2*b)) {
							cost1 += (j+3)*a; cost2 += (j+2)*b; end = 2;
//							cout << "1heyhey!!" << endl;
						} else {
							cost1 += (j+1)*a; cost2 += (j+1)*2*b; end = 2;
//							cout << endl << "2heyhey!!" << endl;
						}
						i += j;
					}
					
				}
			}
//			cout << "cost1 = " << cost1 << " cost2 = " << cost2-b << " " << s[i] << endl;
		}
		printf("%lld\n", cost1+cost2);
	}
}

/*
1
10 2 5
0000000100
*/

// 89