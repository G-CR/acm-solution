#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b;
ll num[1000000],ans[1000000];

int main() {
	scanf("%lld %lld", &a, &b);
	
	int j = 1;
	for(int i = 1;i <= sqrt(a); i++) {
		if(!(a%i)){
			num[j] = i;
			num[j+1] = a/i;
			if(num[j]!=num[j+1]) j += 2;
			else j += 1;
		} 
	}
	j--;	
	int k = 0;
	for(int i = 1;i <= j; i++) {
		if(!(num[i]%b)) ans[++k] = num[i];
	}
	
	sort(ans+1,ans+1+k);
	for(int i = 1;i <= k; i++){
//		if(ans[i] == ans[i-1]) continue;
		printf("%lld ", ans[i]);
	} 
}