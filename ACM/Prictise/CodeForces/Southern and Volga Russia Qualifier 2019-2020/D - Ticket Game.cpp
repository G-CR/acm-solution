#include <bits/stdc++.h>
using namespace std;

int num1, num2, sum1, sum2, n;
char s[200005];

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	for(int i = 1;i <= n/2; i++) {
		if(s[i] == '?') num1++;
		else {
			sum1 += (s[i]-'0');
		}
	}
	
	for(int i = n/2+1;i <= n; i++) {
		if(s[i] == '?') num2++;
		else {
			sum2 += (s[i]-'0');
		}
	}
	
	if(sum1 < sum2) {
		swap(sum1, sum2);
		swap(num1, num2);
	}
	
	int sum = sum1 - sum2;
	if(num1 == num2 && !sum) puts("Bicarp");
	else if(num2 > num1 && sum == (num2-num1)/2*9) puts("Bicarp");
	else puts("Monocarp");
}