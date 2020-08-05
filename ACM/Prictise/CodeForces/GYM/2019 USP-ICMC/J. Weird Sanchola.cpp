#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n;
ll a[100005];
 
bool isPrime(int num) {
	if (num <= 3) {
		return num > 1;
	}
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int t = (int)sqrt(num);
	for (int i = 5; i <= t; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}
 
int main() {
	scanf("%d", &n);
	int mid = n/2;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+1+n);
	ll tmp,ans = 0,ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0,fans1 = -1,fans2 = -1;
	bool ok1 = 0,ok2 = 0,ok3 = 0,ok4 = 0;
	
	
		int i = 0,j = 0;
		while(1) {
			ll lin,lin2,lin3,lin4;
			lin = a[mid] + i;
			lin2 = a[mid] + j;
			lin3 = a[mid+1] + i;
			lin4 = a[mid+1] + j;
			if(lin<2){
				lin=2;
			}
			if(lin2<2){
				lin2=2;
			}
			if(lin3<2){
				lin3=2;
			}
			if(lin4<2){
				lin4=2;
			}
			if(!ok1 && isPrime(lin)) {
				tmp = lin; ok1 = 1;
				for(int k = 1;k <= n; k++) {
					ans1 += abs(tmp-a[k]);
				}
			}
			
			if(!ok2 && isPrime(lin2)) {
				tmp = lin2; ok2 = 1;
				for(int k = 1;k <= n; k++) {
					ans2 += abs(tmp-a[k]);
				}
			}
			
			if(!ok3 && isPrime(lin3)) {
				tmp = lin3; ok3 = 1;
				for(int k = 1;k <= n; k++) {
					ans3 += abs(tmp-a[k]);
				}
			}
			
			if(!ok4 && isPrime(lin4)) {
				tmp = lin4; ok4 = 1;
				for(int k = 1;k <= n; k++) {
					ans4 += abs(tmp-a[k]);
				}
			}
			
			if(ok1 && ok2) fans1 = min(ans1, ans2);
			if(ok3 && ok4) fans2 = min(ans3, ans4);
			if(fans1!=-1 && fans2!=-1) {
//				cout << fans1 << fans2 << endl;
				ans = min(fans1, fans2);
				break;
			}
			i++, j--;
		}
	printf("%lld\n", ans);
	return 0;
}