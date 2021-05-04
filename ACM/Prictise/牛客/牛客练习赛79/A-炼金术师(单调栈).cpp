#include <bits/stdc++.h>
using namespace std;

int n, a;
stack <int> sta;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		while(!sta.empty() && sta.top() <= a) sta.pop();
		sta.push(a);	
	}
	printf("%lu\n", sta.size());
}