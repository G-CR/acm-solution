#include <bits/stdc++.h>
using namespace std;

char a[10], b[10];

int cal(char *a) {
	int n = strlen(a);
	int sum = 1;
	for(int i = 0;i < n; i++) {
		sum *= (a[i]-'A'+1);
	}
	return sum%47;
}

int main() {
	scanf("%s %s", a, b);
	if(cal(a) == cal(b)) puts("GO");
	else puts("STAY");
}