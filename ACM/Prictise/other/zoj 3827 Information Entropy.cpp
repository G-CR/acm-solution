#include <bits/stdc++.h>
using namespace std;
 
char s[10];
int _, n, a[105];
	
int main(){
	scanf("%d", &_);
	while(_--){
		double ans = 0.0;
		scanf("%d %s", &n, s);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
			
		for(int i = 1; i <= n; i++){
			if(a[i] == 0) continue;
			
			double res = (double)(1.0*a[i]*(1.0*log(1.0*a[i]/100))/100);
			if(s[0] == 'b')
				res = (double)res/(1.0*log(2.0));
			if(s[0] == 'd')
				res = (double)res/(1.0*log(10.0));
			ans += res;
		}
		printf("%.10f\n", -1.0*ans);
	}
	return 0;
}